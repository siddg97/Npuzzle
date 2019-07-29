#include <iostream>
#include <string>
#include "modules.h"
#include "problem.h"
#include "heuristics.h"
using namespace std;

Tuple ida_star(Puzzle15* p, string h) {
	Stack* path = new Stack();
	path->push(root);
	int bound;
	if(h=="manhattan"){
		bound = manhattan
	}
}