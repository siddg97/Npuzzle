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

// Tuple* search(Stack* path, int g, int bound){
// 	Tnode* n = path->last();
// 	int f = g + h(n);
// 	if(is_goal(n)){
// 		Tuple* t = new Tuple(path,bound);
// 		t->setINF(false);
// 		t->setType("FOUND");
// 		return t;
// 	}
// 	int min = 2147483647;
// }

int main(){
	
	return 0;
}