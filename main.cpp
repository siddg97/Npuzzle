#include <iostream>
#include <string>
#include "modules.h"
#include "heuristics.h"
using namespace std;

bool inPath(Tnode* n, Stack* path){
	return path->stack->search(n);
}

Tuple* search15(Stack* path,int g,int bound, char c){
	Tnode* n = path->pop();
	int f = g;
	if (c=='m'){
		int temp[16];
		for(int i=0;i<16;i++)
			temp[i]=n->p->Board[i];
		// int temp[16]= *(n->p->Board);
		f+=manhattan(temp,16);
	}
	else{
		f+=euc_sq(n->p->Board,16);
	}
	if(f > bound){
		Tuple* t = new Tuple("FINDING",path,f,false);
		return t;
	}
	if(n->p->isgoal()){
		Tuple* t = new Tuple("FOUND",path,bound,false);
		return t;
	}
	Tuple* min = new Tuple();
	min->inf=true;
	vector<Puzzle15> children= get_moves15(*(n->p));
	for (uint i=0; i < children.size(); i++){
		Tnode* child = new Tnode(&children[i]);
		if(!inPath(child,path)){
			path->push(child);
			Tuple* t = search15(path,g+1,bound,c);
			if(t->type=="FOUND"){
				return t;
			}
			if(!t->inf){
				min = t;
			}
			path->pop();
		}
	}
	return min;
}

Tuple* ida_star15(Puzzle15* p, char c) {
	Tnode* root = new Tnode(p);
	Stack* path = new Stack();
	path->push(root);
	int bound;
	if(c=='m'){
		bound= manhattan(root->p->Board,16);
	} 
	else {
		bound= euc_sq(root->p->Board,16);
	}
	while(true){
		Tuple* t = search15(path,0,bound,c);
		if(t->type=="FOUND"){
			Tuple* res = new Tuple("FOUND",t->path,t->bound,false);
			return res;
		}
		if(t->inf){
			Tuple* res = new Tuple("NOT_FOUND",NULL,0,true);
			return res;
		}
		bound= t->bound;
	}
}

int main(){
	Puzzle15* p= new Puzzle15();
	p->print();
	Tuple* res = ida_star15(p,'m');
	res->path->print_stack();
	cout << endl;
	cout << "COST/STEPS TAKEN= " << res->bound << endl;
	return 0;
}