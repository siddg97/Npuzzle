

class Puzzle15{
public:
	int Board[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	Puzzle15();
	Puzzle15& operator=(const Puzzle15 &L);
	bool operator==(const Puzzle15 &L);
	void print();
	bool solvable();
	bool isgoal();
	enum moves { up='u', down='d', left='l', right='r'};
};

class Puzzle25{
public:
	int Board[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,0};
	Puzzle25();
	Puzzle25& operator=(const Puzzle25 &L);
	bool operator==(const Puzzle25 &L);
	void print();
	bool solvable();
	bool isgoal();
	enum moves { up='u', down='d', left='l', right='r'};
};