#include <iostream>
#include <string>
#include "modules.h"
using namespace std;

Tuple ida_star(Puzzle p){
	Tnode* root = new Tnode();
	Stack* path = new Stack();
	path->push(root);
	root->setData(p.data);
	int bound = h(root);
	while(true){
		Tuple* t = search(path,0,bound);
		if(s=="FOUND"){
			return Tuple(path,bound)
		}
		if(t->inf){
			Tuple* temp = new Tuple();
			temp->setType("NOT_FOUND");
			return temp;
		}
		bound = t->bound;
	}
}

int main(){
	
	return 0;
}