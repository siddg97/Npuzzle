#ifndef PROBLEM_H
#define PROBLEM_H
#include "heuristics.h"
#include <vector>
using namespace std;
//--------FOR PUZZLE 15
class Puzzle15{
public:
	int Board[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	Puzzle15();
	Puzzle15& operator=(const Puzzle15 &L);
	bool operator==(const Puzzle15 &L);
	void print();
	bool solvable();
	bool isgoal();
	int tile_num();
	void shift_up();
	void shift_down();
	void shift_left();
	void shift_right();
};

//CUSTOM SORT FUNCTION FOR VECTOR
struct man_comp15
{
    bool operator() ( Puzzle15& p1, Puzzle15& p2) const
    {
        return (manhattan(p1.Board,16) <= manhattan(p2.Board,16));
    }
};

struct euc_comp15
{
    bool operator() ( Puzzle15& p1,  Puzzle15& p2) const
    {
        return (euc_sq(p1.Board,16) <= euc_sq(p2.Board,16));
    }
};

struct max_h_comp15
{
    bool operator() ( Puzzle15& p1, Puzzle15& p2) const
    {
        return (max_h(p1.Board,16) <= max_h(p2.Board,16));
    }
};

vector<Puzzle15*>* get_moves15(Puzzle15* p, char a);

//--------FOR PUZZLE 25
class Puzzle25{
public:
	int Board[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,0};
	Puzzle25();
	Puzzle25& operator=(const Puzzle25 &L);
	bool operator==(const Puzzle25 &L);
	void print();
	bool solvable();
	bool isgoal();
	int tile_num();	
	void shift_up();
	void shift_down();
	void shift_left();
	void shift_right();
};

vector<Puzzle25*> get_moves25(Puzzle25* p, char a);


struct man_comp25
{
    bool operator() (Puzzle25& p1, Puzzle25& p2)const 
    {
        return (manhattan(p1.Board,25) < manhattan(p1.Board,25));
    }
};

struct euc_comp25
{
    bool operator() ( Puzzle25& p1,  Puzzle25& p2)const
    {
        return (euc_sq(p1.Board,25) <= euc_sq(p2.Board,25));
    }
};

struct max_h_comp25
{
    bool operator() ( Puzzle25& p1,  Puzzle25& p2)const
    {
        return (max_h(p1.Board,25) <= max_h(p2.Board,25));
    }
};




#endif