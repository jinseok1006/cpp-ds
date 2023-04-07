#include "CircularQueue.h"
#include <cstdio>
#include <iostream>
#include<vector>
using namespace std;

struct Block {
	char type;
	bool visited;
};

struct Position {
	int row;
	int col;
};

// type, visited
int N,M;	
vector<vector<Block>> map;
CircularQueue<Position> queue;
Position Dest;

int main() {
	cin>>N>>M;
	vector<Block> buf(M, {0,false});
	map.assign(N, buf);

}