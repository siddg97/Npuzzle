#include "modules.h"
#include "problem.h"
#include <iostream>
using namespace std;

//==========================[NODE and Linked list class implementations]===============================

Node::Node(Tnode* tn, Node* next){
	this->tn = tn;
	this->next = next;
}

Node::Node(){
	this->tn = NULL;
	this->next = NULL;
}

Llist::Llist(){
	this->items = 0;
	this->head = NULL;
}

Llist::~Llist(){
	if(!this->isEmpty()){
		Node* next = this->head;
		Node* curr = NULL;
		while(next!= NULL){
			curr = next;
			next = next->next;
			delete curr;
		}
		this->items = 0;
	}
}

void Llist::insertHead(Tnode* tn){
	Node* h = this->head;
	Node* n = new Node(tn,h);
	this->head = n;
	this->items += 1;
}

void Llist::insertTail(Tnode* tn){
	Node* temp = this->head;
	Node* n = new Node(tn,NULL);
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = n;
	this->items += 1;
}

bool Llist::isEmpty(){
	return this->items == 0;
}

void Llist::deleteHead(){
	if (!this->isEmpty()){
		Node* temp = this->head;
		this->head = temp->next;
		this->items -= 1;
		temp->next = NULL;
		delete temp;
	}
}

Tnode* Llist::getTail(){
	Node* t = this->head;
	while (t->next != NULL){
		t = t->next;
	}
	return t->tn;
}

Tnode* Llist::getHead(){
	return this->head->tn;
}

//======================[length() function Implementation]==============================

int length(Tnode*s arr[]){
	return (sizeof(arr)/sizeof(arr[0]))
}

//======================[STACK Class Implementation]==============================

Stack::Stack(){
	this->stack = new Llist();
}

Stack::~Stack(){
	this->stack->~Llist();
}

void Stack::push(Tnode* tn){
	this->stack->insertHead(tn);
}

Tnode* Stack::pop(){
	if(!this->stack->isEmpty()){
		int poped = this->stack->getHead();
		this->stack->deleteHead();
		return poped;
	}
	else{
		return NULL;
	}
}

Tnode* Stack::getTop(){
	if(!this->stack->isEmpty()){
		return this->Stack->getHead();
	}
	else {
		return NULL;
	}
}

void Stack::print_stack(){
	Node *t = this->stack->head;
	while (t!=NULL){
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

//======================[Tnode and Tree Class Implementation]==============================

Tnode::Tnode(Puzzle15* p){
	this->p = p;
}

// Tnode::Tnode(Tnode* parent,vector<Tnode*> children){
// 	this->p = NULL;
// 	this->parent = parent;
// 	this->children = children;
// }

// Tnode::Tnode(Tnode* parent,vector<Tnode*> children, Puzzle15* p){
// 	this->p = p;
// 	this->parent = parent;
// 	this->children = children;
// }

// Tnode* Tnode::getParent(){
// 	return this->parent;
// }

// void Tnode::setChildren(vector<Tnode*> c){
// 	this->children = c;
// }

// vector<Tnode*> Tnode::getChildren(){
// 	return this->children;
// }

// void Tnode::addChild(Tnode* child){
// 	this->children.push_back(child);
// }

// void Tnode::setData(Puzzle15* p){
// 	this->p = p;
// }

// Puzzle15* Tnode::getData(){
// 	return this->p;
// }

// bool Tnode::isLeaf(){
// 	return this->children.empty();
// }

// bool Tnode::isInternalNode(){
// 	return (this->parent != NULL) && (!this->isLeaf());
// }

// bool Tnode::isRoot(){
// 	return this->parent == NULL;
// }

Tnode::~Tnode(){
	// this->children.~vector();
	this->parent = NULL;
	// this->data = 0;
}

//======================[Tuple Class Implementation]==============================

Tuple::Tuple(){
	this->path=NULL;
	this->bound=0;
	this->type = "";
	bool inf = false;
}

Tuple::Tuple(Stack* path, int bound){
	this->bound = bound;
	this->path = path;
}

void Tuple::setINF(bool inf){
	this->inf = inf;
}

void Tuple::setBound(int b){
	this->bound = b;
}

void Tuple::setPath(Stack* path){
	this->path = path;
}

Tuple::~Tuple(){
	this->type="";
	this->bound=0;
	this->path->~Stack();
}