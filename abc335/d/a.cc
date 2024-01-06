#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N, -1));
  int x = 0, y = 0;
  int k = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  A[0][0] = 1;
  int count = 2;
  while (count < N * N) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N || A[ny][nx] >= 0) {
      k = (k + 1) % 4;
      continue;
    }
    A[ny][nx] = count;
    x = nx;
    y = ny;
    count++;
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (A[y][x] >= 0) {
        cout << A[y][x];
      } else {
        cout << 'T';
      }
      if (x == N - 1) {
        cout << '\n';
      } else {
        cout << ' ';
      }
    }
  }
  return 0;
}
