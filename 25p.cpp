#include <iostream>
#include <ctime>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
// typedefs for unsigned types
typedef unsigned int ui;
typedef unsigned char uc;

// Global vars
bool isSolved = false;
int Size;
char mdTable[25][25];
char movableTable[25][4];
uc path[256];
ui nodeCount;
char dirs[4] = {-1, 1, -2, 2};
char moves[24][4];

struct NodeInfo {
	ui id;
	ui parent;
	char blank;
	char move;
};

struct Node {
	char board[25];
	char move;
	NodeInfo nodeInfo;
	uc f, g;

	Node(char* bd, char blk, char move, ui id, ui parent, uc f = 0, uc g = 0){
		for (int i = 0; i < Size * Size; ++i)		{
			board[i] = bd[i];
		}
		nodeInfo.blank = blk;
		nodeInfo.id = id;
		nodeInfo.parent = parent;
		nodeInfo.move = move;
		this->f = f;
		this->g = g;
	}

	bool operator >(const Node& other) const{
		return f > other.f;
	}
};

void MakeDirections(){
	int i = 0;
	char dirs[] = {0, 1, 2, 3};
	do{
		moves[i][0] = dirs[0];
		moves[i][1] = dirs[1];
		moves[i][2] = dirs[2];
		moves[i++][3] = dirs[3];
	}while ( next_permutation(dirs, dirs + 4) );
}

void MakeMovableTable(int size){
	int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int board[5][5];
	for(int y = 0; y < size; ++y){
		for(int x = 0; x < size; ++x){
			board[y][x] = x + y * size;
		}
	}
	int dx, dy, j;
	for(int y = 0; y < size; ++y){
		for(int x = 0; x < size; ++x){
			for(int i = 0; i < 4; ++i){
				dx = moves[i][0];
				dy = moves[i][1];
				if(x + dx < 0 || y + dy < 0 || x + dx >= size || y + dy >= size){
					j = -1;
				}
				else{
					j = board[y + dy][x + dx];
				} 
				movableTable[x + y * size][i] = j;
			}
		}
	}
}

void MakeMDTable(int size){
	for(int y = 0, i = 1; y < size * size; ++y, (++i) % (size * size)){
		for(int x = 0; x < size * size; ++x){
			if(i == 0){
				mdTable[i][x] = 0;
			}
			else{
				mdTable[i][x] = abs((y / size) - (x / size)) + abs((y % size) - (x % size));
			}
		}
	}
}

char GetDistance(int *row, char md, int nums){
	if (nums > 1){
		if (nums == 2){
			if (row[0] > row[1])
				md += 2;
		}
		else if (nums == 3){
			if (row[0] > row[1] || row[0] > row[2])
				md += 2;
			if (row[1] > row[2])
				md += 2;
		}
		else if (nums == 4){
			if (row[0] > row[1] || row[0] > row[2] || row[0] > row[3])
				md += 2;
			if (row[1] > row[2] || row[1] > row[3])
				md += 2;
			if (row[2] > row[3])
				md += 2;
		}
		else if (nums == 5){
			if (row[0] > row[1] || row[0] > row[2] || row[0] > row[3] || row[0] > row[4])
				md += 2;
			if (row[1] > row[2] || row[1] > row[3] || row[1] > row[4])
				md += 2;
			if (row[2] > row[3] || row[2] > row[4])
				md += 2;
			if(row[3] > row[4])
				md += 2;
		}
	}
	return md;
}

char GetHeuristic(char* puzzle){
	int i, j, x, md = 0;
	int k, n;
	int temp[5];

	for(i = 0; i < Size * Size; ++i){
		md += mdTable[puzzle[i]][i];
	}

	for (i = 0, x = 1; i < Size; ++i, ++x){
		k = 0;
		for (j = 0; j < Size; ++j)
		{
			n = puzzle[i * Size + j];
			if (n <= Size * x && n > Size * (x - 1))
			{
				temp[k++] = n;
			}
		}
		md = GetDistance(temp, md, k);
	}
	 
	for (i = 0, x = 1; i < Size; ++i, ++x){
		k = 0;
		for (j = 0; j < Size; ++j){
			n = puzzle[j * Size + i];
			if (n == x || n == x + Size || n == x + Size * 2 || n == x + Size * 3){
				temp[k++] = n;
			}
		}
		md = GetDistance(temp, md, k);
	}
	return md;
} 

char GetBlank(char *puzzle){
	for(int i = 0; i < Size * Size; ++i){
		if (puzzle[i] == 0){
			return i;
		}
	}
}

void PrintPath(char depth){
	for(int i = 0; i < depth; ++i){
		printf("%2d  ",path[i]);
		if((i + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n\n");
}

void PrintPuzzle(char* puzzle){
	for(int i = 0; i < Size; ++i){
		for(int j = 0; j < Size; ++j){
			printf("%2d ", puzzle[i * Size + j]);
		}
		printf("\n");
	}
	printf("\n");
}

int i = 0;
void IdaStar(char maxDepth, char* puzzle, char lastMove, char blank, char dir){
	if (maxDepth == 0){
		isSolved = true;
		return;
	} 
	else{
		for (int j = 0; j < 4; ++j){
			if(lastMove == -1 || (dirs[moves[dir][j]] + dirs[lastMove]) != 0){
				char newBlank = movableTable[blank][moves[dir][j]];
				if(newBlank == -1)
					continue;
				puzzle[blank] = puzzle[newBlank];
				puzzle[newBlank] = 0; 
				uc h = GetHeuristic(puzzle);
				if(h < maxDepth && !isSolved){
					nodeCount += 1;
					path[i++] = puzzle[blank];
					IdaStar(maxDepth - 1, puzzle, moves[dir][j], newBlank, dir);
					--i;
				}
				puzzle[newBlank] = puzzle[blank];
				puzzle[blank] = 0;
			}
		}
	}
}

void IDAStar(char* puzzle, char dir){
	time_t start, end;
	uc h, depth;
	char lastMove = -1;
	char blank = GetBlank(puzzle);
	isSolved = false;
	ui totalCount = 0;
	h = GetHeuristic(puzzle);
	depth = h;
	start = clock();
	while (true){
		nodeCount = 0;
		IdaStar(depth, puzzle, lastMove, blank, dir);
		end = clock();
		totalCount += nodeCount;
		printf("Depth = %d, Node Count = %10u, Total Count = %10u, time = %6.2f seconds\n",depth, nodeCount, totalCount, (end - start) / 1000.);
		if (isSolved){
			printf("Total Node Count = %u, shortest path length = %d, time = %.2f seconds\n",totalCount, depth, (end - start) / 1000.);
			return;
		}
		depth += 2;
	}
}


void shuffle_array(char arr[], int n) { //from : https://www.geeksforgeeks.org/shuffle-an-array-using-stl-in-c/
    // To obtain a time-based seed 
    unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
    // Shuffling our array 
    shuffle(arr, arr + n, default_random_engine(seed)); 
}

int* toInt(char * c , int s){
 	int *board=new int[s];
	for(int i=0;i<s;i++){
		int a=(int) c[i];
		board[i]=a;
	}
	return board;
} 

bool solvable(char * c){
	int *board=toInt(c,25);
	// for(int i=0;i<16;i++)
	// 	cout<<board[i]<<" ";
	// cout<<endl;
	int count=0;
	for(int i=0;i<24;i++){ 
        for (int j=i+1;j<25;j++)
             if(board[i]>board[j] && board[i]!=0 &&board[j]!=0){ 
                 count++;
             }
    }
    return (count%2+1)%2;
}

int main()
{
	int  size = 5;
	char puzzle[25]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,0};
	char p[25];
	srand((ui)time(NULL));
	char dir = rand() % 24;
	MakeMDTable(size);
	MakeMovableTable(size);
	MakeDirections();
	Size = size;
	shuffle_array(puzzle,25);
	while(!solvable(puzzle)){
		shuffle_array(puzzle,25);
	}
	cout << "  PUZZLE TO SOLVE  \n--------------------" << endl << endl;
	PrintPuzzle(puzzle);
	cout << "--------------------" << endl << endl;
	// cout<<solvable(puzzle)<<endl;
	printf("\n===== IDA Star Algiorithm =====\n");
	IDAStar(puzzle, dir);

	return 0;
}
