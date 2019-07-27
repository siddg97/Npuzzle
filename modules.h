#include <vector>
#include <string>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int d, Node* next);
	Node();
};

class Llist{
public:
	int items;
	Node* head;
	Llist();
	bool isEmpty();
	~Llist();
	void insertHead(int data);
	void insertTail(int data);
	void deleteHead();
	int getTail();		// !!!! Assumes that ll is not empty !!!!
	int getHead();		// !!!! Assumes that ll is not empty !!!!
};

class Stack {
public:
	Llist* stack;
	Stack();
	~Stack();
	void push(int d);
	int pop();		// returns -1 if stack is empty
	int last();		// return the last element in the stack
	void print_stack();
};

class Tnode{
public:
	Tnode* parent;
	vector <Tnode*> children;
	int data;
	Tnode();
	Tnode(Tnode* parent, vector<Tnode*> children);
	Tnode(Tnode* parent, vector<Tnode*> children, int data);
	Tnode* getParent();
	void setChildren(vector<Tnode*> c);
	vector<Tnode*> getChildren();
	void addChild(Tnode* child);
	void setData(int d);
	int getData();
	bool isLeaf();
	bool isInternalNode();
	bool isRoot();
	~Tnode();
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