#include <iostream>
#include <string>
#include "modules.h"
#include "heuristics.h"
using namespace std;

Tuple* search15(Stack* path,int g,int bound, char c){
	Tnode* n = path->pop();
	int f = g;
	if (c=='m'){
		f+=manhattan(n->p->Board,16);
	}
	else{
		f+=euc_sq(n->p->Board,16);
	}
	if(f > bound){
		Tuple* t = new Tuple();
		t->type="FINDING";
		t->bound=f;
		t->path=path;
		t->inf=false;
		return t;
	}
	if(n->p->isgoal()){
		Tuple* t = new Tuple();
		t->type="FOUND";
		t->bound=bound;
		t->path=path;
		t->inf=false;
		return t;
	}
	Tuple* min = new Tuple();
	min->inf=true;
	Tnode* children[] = getChildren(n);
	for (int i=0; i < length(children); i++){
		if(!inPath(children[i],path)){
			path->push(children[i]);
			Tuple* t = search15(path,g+cost(n,children[i]),bound);
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
		bound = manhattan(root->p->Board,16);
	} 
	else {
		bound= euc_sq(root->p->Board,16);
	}
	while(true){
		Tuple* t = search15(path,0,bound,c);
		if(t->type=="FOUND"){
			Tuple* res = new Tuple();
			res->setPath(t->path);
			res->setBound(t->bound);
			return res;
		}
		if(t->inf){
			Tuple* res = new Tuple();
			res->type="NOT_FOUND";
			return res;
		}
		bound = t->bound;
	}
}