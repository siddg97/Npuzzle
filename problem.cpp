#include <iostream>
#include <random> 
#include <bits/stdc++.h>
#include "problem.h"
using namespace std;

void shuffle_array(int arr[], int n) { //from : https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/
    // To obtain a time-based seed 
    unsigned seed = 0; 
  
    // Shuffling our array 
    shuffle(arr, arr + n, 
            default_random_engine(seed)); 
} 

Puzzle15::Puzzle15(){
	shuffle_array(this->Board,16);
	// int a=this->Board[14];
 //  	while(this->isgoal()==0)
	// 	shuffle_array(this->Board,16);
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

Puzzle25::Puzzle25(){
	shuffle_array(this->Board,25);
	// int a=this->Board[14];
 //  	while(this->isgoal()==0)
	// 	shuffle_array(this->Board,16);
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

int main(){
	Puzzle15 p = Puzzle15();
	//int a= p.Board[15];
	//p.Board[11]=15;
	//p.Board[14]=12;
	for(int i=0; i<16;i++){
		cout<<" "<<p.Board[i];
	}
	cout<<endl;
	p.print();
	cout<<p.solvable()<<endl;
	return 0;
}
