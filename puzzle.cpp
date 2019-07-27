#include "modules.h"
#include <iostream>
#include <random> 
#include <bits/stdc++.h>
using namespace std;

void shuffle_array(int arr[], int n) { //from : https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/
    // To obtain a time-based seed 
    unsigned seed = 0; 
  
    // Shuffling our array 
    shuffle(arr, arr + n, 
            default_random_engine(seed)); 
} 

class Puzzle{
public:
	int Board[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

	Puzzle();
	Puzzle& operator=(const Puzzle &L);
	bool operator==(const Puzzle &L);
	void print();
	bool solvable();
	bool isgoal();
	enum moves { up='u', down='d', left='l', right='r'};
};

Puzzle::Puzzle(){
	shuffle_array(this->Board,16);
	// int a=this->Board[14];
 //  	while(this->isgoal()==0)
	// 	shuffle_array(this->Board,16);
}

Puzzle& Puzzle::operator=(const Puzzle &L){
	if(this==&L)
		return *this;
	for(int i=0; i<16;i++)
		this->Board[i]=L.Board[i];
	return *this;
}

bool Puzzle::operator==(const Puzzle &L) {
	for(int i=0;i<16;i++)
	{
		if(this->Board[i]!=L.Board[i])
			return false;
	}
	return true;
}

void Puzzle::print(){
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

bool Puzzle::solvable(){
	int count=0;
	for(int i=0;i<15;i++){ 
        for (int j=i+1;j<16;j++)
             if(this->Board[i]>this->Board[j] && this->Board[i]!=0 &&this->Board!=0) 
                 count++;
    }
    return count%2+1;
}

bool Puzzle::isgoal(){
	int arr[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	if(this->Board==arr)
		return true;
	return false;
}

int main(){
	Puzzle p=Puzzle();
	for(int i=0; i<16;i++){
		cout<<" "<<p.Board[i];
	}
	cout<<endl;
	p.print();
	cout<<p.solvable()<<endl;
	return 0;
}