#include <iostream>
#include <random> 
#include <math.h>
#include "heuristics.h"
using namespace std;

int get_row(int x,int s){ //x starts from 1
	int p=static_cast<int>((x-1)/s);
	//cout<<"row is :"<<p<<endl;
	return p;
}

int get_column(int x,int s){ //x starts from 1
	int p=0;
	if (x%s==0){
		p=s;
	}
	else{
		p=x%s;
	}
	//cout<<"col is :"<<p<<endl;
	return p;
}

int manhattan(int board[],int s){
	int n=sqrt(s);
	// cout<<n<<endl;
	int m=0;//manhattan sum
	for(int i =0;i<s;i++){
		if(board[i]==0){
			//cout<<"continue"<<endl;
			continue;
		}
		else{
			int k=abs(get_column(i+1,n)-get_column(board[i],n))+abs(get_row(i+1,n)-get_row(board[i],n));
			//cout<<"first k "<<k<<endl;
			m+=k;
		}

	}
	return m;
}

float euc_sq(int *board,int s){
	int n=sqrt(s);
	int e=0;//euclidean sum
	for(int i =0;i<s;i++){
		if(board[i]==0||board[i]==i+1)
			continue;
		else
			e+=pow(get_column(i+1,n)-get_column(board[i],n),2)+pow(get_row(i+1,n)-get_row(board[i],n),2);
	}
	//cout<<e<<endl;
	float sq_e=sqrt(e);
	return sq_e;
}

int max_h(int *board, int s){
	if(manhattan(board,s)>=euc_sq(board,s))
		return manhattan(board,s);
	return static_cast<int>(euc_sq(board,s));
}

// int main(){

// 	int b[9]={1,2,3,4,5,6,7,0,8};
// 	cout<<sizeof(b)<<endl;
// 	int s=sizeof(b)/sizeof(int);
// 	cout<<s<<endl;
// 	// cout<<sizeof(int);
// 	//float p=euc_sq(b);
// 	int p=euc_sq(b,s);
// 	cout<<p;
// 	return 0;
// }