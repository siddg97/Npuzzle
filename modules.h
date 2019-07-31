#ifndef MODULES_H
#define MODULES_H

#include <string>
#include "problem.h"
using namespace std;

class Tnode{
public:
	Puzzle15* p;
	Tnode(Puzzle15* p);
	bool operator==(const Tnode &n);
};

class Node{
public:
	Tnode* tn;
	Node* next;
	Node(Tnode* tn, Node* next);
	Node();
};

class Llist{
public:
	int items;
	Node* head;
	Llist();
	bool isEmpty();
	~Llist();
	void insertHead(Tnode* tn);
	void insertTail(Tnode* tn);
	void deleteHead();
	Tnode* getTail();		// !!!! Assumes that ll is not empty !!!!
	Tnode* getHead();		// !!!! Assumes that ll is not empty !!!!
	bool search(Tnode* tn);
};

class Stack {
public:
	Llist* stack;
	Stack();
	~Stack();
	void push(Tnode* tn);
	Tnode* pop();		// returns NULL if stack is empty
	Tnode* getTop();	// returns NULL if stack is empty
	void print_stack();
};

class Tuple {
public:
	string type;
	Stack* path;
	int bound;
	bool inf;
	Tuple();
	Tuple(Tuple* t);
	Tuple(string type,Stack* path, int bound, bool inf);
	~Tuple();
};

#endif