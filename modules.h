#include <vector>
#include <string>
#include "problem.h"
using namespace std;

class Tnode{
public:
	Tnode* parent;
	vector <Tnode*> children;
	Puzzle15* p;
	Tnode(Puzzle15* p);
	Tnode(Tnode* parent, vector<Tnode*> children);
	Tnode(Tnode* parent, vector<Tnode*> children, Puzzle15* p);
	Tnode* getParent();
	void setChildren(vector<Tnode*> c);
	vector<Tnode*> getChildren();
	void addChild(Tnode* child);
	void setData(Puzzle15* p);
	Puzzle15* getData();
	bool isLeaf();
	bool isInternalNode();
	bool isRoot();
	~Tnode();
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
};

class Stack {
public:
	Llist* stack;
	Stack();
	~Stack();
	void push(Tnode* tn);
	Tnode* pop();		// returns NULL if stack is empty
	Tnode* getTop();
	void print_stack();
};

class Tuple {
public:
	string type;
	Stack* path;
	int bound;
	bool inf;
	Tuple();
	Tuple(Stack* path, int bound);
	void setINF(bool inf);
	void setBound(int b);
	void setPath(Stack* path);
	~Tuple();
};