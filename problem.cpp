#include <iostream>
#include <random> 
#include <bits/stdc++.h>
#include "problem.h"
#include <vector>
#include <chrono>
#include "heuristics.h"
using namespace std;

void shuffle_array(int arr[], int n) { //from : https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/
    // To obtain a time-based seed 
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
  
    // Shuffling our array 
    shuffle(arr, arr + n, 
            default_random_engine(seed)); 
} 

Puzzle15::Puzzle15(){
	shuffle_array(this->Board,16);
  	while(this->solvable()==0)
		shuffle_array(this->Board,16);
}

Puzzle15& Puzzle15::operator=(const Puzzle15 &L){
	if(this==&L)
		return *this;
	for(int i=0; i<16;i++)
		this->Board[i]=L.Board[i];
	return *this;
}

bool Puzzle15::operator==(const Puzzle15 &L) {
	for(int i=0;i<16;i++)
	{
		if(this->Board[i]!=L.Board[i])
			return false;
	}
	return true;
}

void Puzzle15::print(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<"| ";
			if(this->Board[i*4+j]==0)
				cout<<"* | ";
			else if(this->Board[i*4+j]>=10)
				cout<<this->Board[i*4+j]<<"| ";
			else
				cout<<this->Board[i*4+j]<<" | ";

		}
		cout<<endl;
	}
}

bool Puzzle15::solvable(){
	int count=0;
	for(int i=0;i<15;i++){ 
        for (int j=i+1;j<16;j++)
             if(this->Board[i]>this->Board[j] && this->Board[i]!=0 &&this->Board[j]!=0) 
                 count++;
    }
    cout<<count<<endl;
    return (count%2+1)%2;
    //return count%2;
}

bool Puzzle15::isgoal(){
	int arr[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	if(this->Board==arr)
		return true;
	return false;
}

int Puzzle15::tile_num(){
	for(int i=0;i<16;i++){
		if(this->Board[i]==0)
			return i+1;
	}
	return 0;
}

void Puzzle15::shift_up(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i-5];
	this->Board[i-5]=0;
}
void Puzzle15::shift_down(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i+3];
	this->Board[i+3]=0;
}
void Puzzle15::shift_left(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i-2];
	this->Board[i-2]=0;
}
void Puzzle15::shift_right(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i];
	this->Board[i]=0;
}


//25 Puzzle member functions

Puzzle25::Puzzle25(){
	shuffle_array(this->Board,25);
  	while(this->solvable()==0)
		shuffle_array(this->Board,25);
}

Puzzle25& Puzzle25::operator=(const Puzzle25 &L){
	if(this==&L)
		return *this;
	for(int i=0; i<25;i++)
		this->Board[i]=L.Board[i];
	return *this;
}

bool Puzzle25::operator==(const Puzzle25 &L) {
	for(int i=0;i<25;i++)
	{
		if(this->Board[i]!=L.Board[i])
			return false;
	}
	return true;
}

void Puzzle25::print(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<"| ";
			if(this->Board[i*5+j]==0)
				cout<<"* | ";
			else if(this->Board[i*5+j]>=10)
				cout<<this->Board[i*5+j]<<"| ";
			else
				cout<<this->Board[i*5+j]<<" | ";

		}
		cout<<endl;
	}
}

bool Puzzle25::solvable(){
	int count=0;
	for(int i=0;i<24;i++){ 
        for (int j=i+1;j<25;j++)
             if(this->Board[i]>this->Board[j] && this->Board[i]!=0 &&this->Board[j]!=0) 
                 count++;
    }
    return (count%2+1)%2;
}

bool Puzzle25::isgoal(){
	int arr[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,0};
	if(this->Board==arr)
		return true;
	return false;
}

int Puzzle25::tile_num(){
	for(int i=0;i<25;i++){
		if(this->Board[i]==0)
			return i+1;
	}
	return 0;
}

void Puzzle25::shift_up(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i-6];
	this->Board[i-6]=0;
}
void Puzzle25::shift_down(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i+4];
	this->Board[i+4]=0;
}
void Puzzle25::shift_left(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i-2];
	this->Board[i-2]=0;
}
void Puzzle25::shift_right(){
	int i= this->tile_num();
	this->Board[i-1]=this->Board[i];
	this->Board[i]=0;
}

// int get_row(int x,int s){ //x starts from 1
// 	int p=static_cast<int>((x-1)/s);
// 	//cout<<"row is :"<<p<<endl;
// 	return p;
// }

// int get_column(int x,int s){ //x starts from 1
// 	int p=0;
// 	if (x%s==0){
// 		p=s;
// 	}
// 	else{
// 		p=x%s;
// 	}
// 	//cout<<"col is :"<<p<<endl;
// 	return p;
// }

vector<Puzzle15> get_moves15(Puzzle15 p){
	vector<Puzzle15> vect;
	int num=p.tile_num();
	//cout<<num<<endl;
	int x=get_row(num,4)+1;
	int y=get_column(num,4);
	if(x>1){
		Puzzle15 new1=p;
		new1.shift_up();
		vect.push_back(new1);
	}
	if(x<4){
		Puzzle15 new1=p;
		new1.shift_down();
		vect.push_back(new1);		
	}
	if(y<4){
		Puzzle15 new1=p;
		new1.shift_right();
		vect.push_back(new1);	
	}
	if(y>1){
		Puzzle15 new1=p;
		new1.shift_left();
		vect.push_back(new1);			
	}
	return vect;
}

vector<Puzzle25> get_moves25(Puzzle25 p){
	vector<Puzzle25> vect;
	int num=p.tile_num();
	//cout<<num<<endl;
	int x=get_row(num,5)+1;
	int y=get_column(num,5);
	if(x>1){
		Puzzle25 new1=p;
		new1.shift_up();
		vect.push_back(new1);
	}
	if(x<5){
		Puzzle25 new1=p;
		new1.shift_down();
		vect.push_back(new1);		
	}
	if(y<5){
		Puzzle25 new1=p;
		new1.shift_right();
		vect.push_back(new1);	
	}
	if(y>1){
		Puzzle25 new1=p;
		new1.shift_left();
		vect.push_back(new1);			
	}
	return vect;
}

// int main(){
// 	Puzzle15 p = Puzzle15();
// 	//int a= p.Board[15];
// 	//p.Board[11]=15;
// 	//p.Board[14]=12;
// 	for(int i=0; i<16;i++){
// 		cout<<" "<<p.Board[i];
// 	}
// 	cout<<p.solvable()<<endl;
// 	cout<<endl;
// 	p.print();
// 	//cout<<p.solvable()<<endl;
// 	vector<Puzzle15> vect=get_moves15(p);
// 	for(int i=0;i<vect.size();i++){
// 		vect[i].print();
// 		cout<<endl;
// 	}

// 	return 0;
// }
