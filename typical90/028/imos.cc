// https://atcoder.jp/contests/typical90/tasks/typical90_ab

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int M = 1000;
  vector<vector<int> > imos(M + 1, vector<int>(M + 1, 0));
  for (int n = 0; n < N; n++) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    imos[ly][lx]++;
    imos[ly][rx]--;
    imos[ry][lx]--;
    imos[ry][rx]++;
  }
  for (int x = 0; x < M; x++) {
    for (int y = 0; y < M; y++) {
      imos[y + 1][x] += imos[y][x];
    }
  }
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      imos[y][x + 1] += imos[y][x];
    }
  }
  vector<int> A(N + 1, 0);
  for (int x = 0; x < M; x++) {
    for (int y = 0; y < M; y++) {
      int k = imos[y][x];
      if (0 < k && k <= N) {
        A[k]++;
      }
    }
  }
  for (int k = 1; k <= N; k++) {
    cout << A[k] << '\n';
  }
  return 0;
}
