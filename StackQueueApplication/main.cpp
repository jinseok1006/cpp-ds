#include "ArrayStack.h"
#include "CircularDeque.h"

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Block {
  // '0': ���, '1': ��, 's': �����, 't': ������
  char type;
  bool visited;
};

// ���Ҷ� pair�� ���°� ���ڴ�..
struct Position {
  int row;
  int col;
  string print() {
    ostringstream oss;
    oss << "(" << row << ", " << col << ")";

    return oss.str();
  }
};

int N, M;
vector<vector<Block>> map;
ArrayStack<Position> stack;
Position destination;
vector<Position> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool bfs();
bool isValidBlock(Position p);

int main() {
  cin >> N >> M;
  vector<Block> col(M, {0, false});
  map.assign(N, col);

  char buf;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> buf;
      map[i][j].type = buf;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j].type == 'S')
        stack.push({i, j});
      if (map[i][j].type == 'T')
        destination = {i, j};
    }
  }

  auto can = bfs();

  cout << (can ? "true" : "false") << endl;

  return 0;
}

bool dfs() {
  while (!stack.empty()) {
    auto cur_loc = stack.pop();
    auto col = cur_loc.col, row = cur_loc.row;
    cout<<cur_loc.print() <<' ';

    if (row == destination.row && col == destination.col)
      return true;

    if (!map[row][col].visited) {
      map[row][col].visited = true;

      for (auto const &d : delta) {
        Position next_loc = {row + d.row, col + d.col};

        if (isValidBlock(next_loc))
          stack.push(next_loc);
      }
    }
  }

  return false;
}

bool isValidBlock(Position pos) {
  // cannot use structured binding in c++11 (c++17 only)
  int row = pos.row;
  int col = pos.col;
  // ���� ���� Ž���ϴ� ���
  if (row < 0 || col < 0 || row >= N || col >= M)
    return false;
  // ���� Ž���ϴ� ���
  else if (map[row][col].type == '1')
    return false;
  // �̹� �湮�� ���� ���
  else if (map[row][col].visited)
    return false;

  return true;
}
