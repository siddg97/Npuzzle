#ifndef MODULES_H
#define MODULES_H

#include <stack>
#include <string>
#include <vector>
#include "problem.h"
using namespace std;

class Node {
public:
	Puzzle15 p;
	Node(Puzzle15 p);
	bool operator==(const Node &n);
};

class Sol{
public:
	string s;
	vector<Node> path;
	int bound;
	Sol(string s,vector<Node> p, int b);
};
#endif