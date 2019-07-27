#include "modules.h"
#include <iostream>
using namespace std;

//==========================[NODE and Linked list class implementations]===============================

Node::Node(int d, Node* next){
	this->data = d;
	this->next = next;
}

Node::Node(){
	this->data = 0;
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

void Llist::insertHead(int data){
	Node* h = this->head;
	Node* n = new Node(data,h);
	this->head = n;
	this->items += 1;
}

void Llist::insertTail(int data){
	Node* temp = this->head;
	Node* n = new Node(data,NULL);
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

int Llist::getTail(){
	Node* t = this->head;
	while (t->next != NULL){
		t = t->next;
	}
	return t->data;
}

int Llist::getHead(){
	return this->head->data;
}

//======================[STACK Class Implementation]==============================

Stack::Stack(){
	this->stack = new Llist();
}

Stack::~Stack(){
	this->stack->~Llist();
}

void Stack::push(int d){
	this->stack->insertHead(d);
}

int Stack::pop(){
	if(!this->stack->isEmpty()){
		int poped = this->stack->getHead();
		this->stack->deleteHead();
		return poped;
	}
	else{
		return -1;
	}
}

int Stack::last(){
	return this->stack->getTail();
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

Tnode::Tnode(){
	this->data = 0;
	this->parent = NULL;
	this->children = NULL;
}

Tnode::Tnode(Tnode* parent,vector<Tnode*> children){
	this->data = 0;
	this->parent = parent;
	this->children = children;
}

Tnode::Tnode(Tnode* parent,vector<Tnode*> children, int data){
	this->data = data;
	this->parent = parent;
	this->children = children;
}

Tnode* Tnode::getParent(){
	return this->parent;
}

void Tnode::setChildren(vector<Tnode*> c){
	this->children = c;
}

vector<Tnode*> Tnode::getChildren(){
	return this->children;
}

void Tnode::addChild(Tnode* child){
	this->children.push_back(child);
}

void Tnode::setData(int d){
	this->data = d;
}

int Tnode::getData(){
	return this->data;
}

bool Tnode::isLeaf(){
	return this->children.empty();
}

bool Tnode::isInternalNode(){
	return (this->parent != NULL) && (!this->isLeaf());
}

bool Tnode::isRoot(){
	return this->parent == NULL;
}

Tnode::~Tnode(){
	this->children.~vector();
	this->parent = NULL;
	this->data = 0;
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