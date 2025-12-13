#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > board(N, vector<int>(N, -1));
  int y = 0;
  int x = (N + 1) / 2 - 1;
  board.at(y).at(x) = 1;
  for (int i = 2; i <= N * N; i++) {
    int ny = (y - 1 + N) % N;
    int nx = (x + 1) % N;
    if (board.at(ny).at(nx) > 0) {
      ny = (y + 1) % N;
      nx = x;
    }
    board.at(ny).at(nx) = i;
    y = ny;
    x = nx;
  }
  for (int y = 0; y < N; y++) {
    dump(board.at(y));
  }
  return 0;
}
