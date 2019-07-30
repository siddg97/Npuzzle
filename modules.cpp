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

bool Llist::search(Tnode* tn){
	Node* temph= this->head;
	while(temph != NULL){
		if(tn == temph->tn){
			return true;
		}
		temph = temph->next;
	}
	return false;
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
		Tnode* poped = this->stack->getHead();
		this->stack->deleteHead();
		return poped;
	}
	else{
		return NULL;
	}
}

Tnode* Stack::getTop(){
	if(!this->stack->isEmpty()){
		return this->stack->getHead();
	}
	else {
		return NULL;
	}
}

void Stack::print_stack(){
	Node *t = this->stack->head;
	while (t!=NULL){
		t->tn->p->print();
		cout << endl << endl << endl;
		t = t->next;
	}
	cout << endl;
}

//======================[Tnode and Tree Class Implementation]==============================

Tnode::Tnode(Puzzle15* p){
	this->p = p;
}

bool operator==(const Tnode &n1,const Tnode &n2){
	return (n1.p == n2.p);
}

//======================[Tuple Class Implementation]==============================

Tuple::Tuple(){
	this->path=NULL;
	this->bound=0;
	this->type = "";
	this->inf = false;
}

Tuple::Tuple(string type, Stack* path, int bound, bool inf){
	this->type = type;
	this->bound = bound;
	this->path = path;
	this->inf = inf;
}

Tuple::~Tuple(){
	this->type="";
	this->bound=0;
	this->path->~Stack();
}