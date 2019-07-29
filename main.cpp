#include <iostream>
#include <string>
#include "modules.h"
#include "heuristics.h"
using namespace std;

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
		Tuple* t = search15(path,0,bound);
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

// Tuple* search15(Stack* path,int g,int bound){
// 	Tnode* 
// }