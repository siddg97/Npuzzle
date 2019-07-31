#include "modules.h"
#include "problem.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Node::Node(Puzzle15 p){
	this->p = p;
}

bool Node::operator==(const Node &n){
	return this->p == n.p;
}

Sol::Sol(string s, vector<Node> p, int b){
	this->s= s;
	this->p= p;
	this->bound= b;
}