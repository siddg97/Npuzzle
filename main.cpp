#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "modules.h"
#include "heuristics.h"
using namespace std;

bool in_path(vector<Node> p, Node n){
	std::vector<Node>::iterator it;
	it = std::find (p.begin(), p.end(), n);
	return (it!=p.end());
}

string search15(vector<Node> p, int g, int bound){
	cout << "In search15()..." << endl;
	Node n= p.front();
	int f = g + manhattan(n.p.Board,16);
	if(f > bound)
		return to_string(f);
	if(n.p.isgoal()){
		return "FOUND";
	}
	string min= "INF";
	vector<Puzzle15> succs= get_moves15(n.p);
	for(uint i=0;i<succs.size();i++){
		Node c= Node(succs[i]);
		if(!in_path(p,c)){
			p.push_back(c);
			string t = search15(p,g+1,bound);
			if(t=="FOUND")
				return "FOUND";
			if(t!="INF")
				min = t;
			p.pop_back();
		}
	}
	return min;
}


Sol ida_star15(Puzzle15 puzz){
	Node root= Node(puzz);
	int bound= manhattan(puzz.Board,16);
	cout << "BOUND= " << bound << endl;
	std::vector<Node> path;
	path.push_back(root);
	while(true){
		cout << "In ida_star15()..." << endl;
		string t= search15(path,0,bound);
		if(t=="FOUND"){
			Sol res= Sol("FOUND",path,bound);
			return res;
		}
		if(t=="INF"){
			Sol res= Sol("NOT_FOUND",path,bound);
			return res;
		}
		bound= stoi(t);
	}
}

int main(){
	Puzzle15* p = new Puzzle15();
	p->print();
	Sol s = ida_star15(*p);
	cout << "RESULT= " << s.s << "COST= " << s.bound << endl;
	for(uint i=0;i<s.p.size();i++){
		s.p[i].p.print();
	}
	return 0;
}