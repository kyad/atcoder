#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

bool check(vector<int> A) {
  assert((int)A.size() == N);
  vector<int> count(N + 1, 0);
  for (int a : A) {
    count.at(a)++;
  }
  bool ans = true;
  for (int i = 1; i <= N; i++) {
    if (count[i] != 1) {
      ans = false;
      break;
    }
  }
  return ans;
}

int main() {
  int N = 9;
  vector<vector<int> > A(N, vector<int>(N, 0));
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> A.at(y).at(x);
    }
  }
  // 行
  bool ans = true;
  for (int y = 0; y < N; y++) {
    if (!check(A.at(y))) {
      ans = false;
      break;
    }
  }
  // 列
  for (int x = 0; x < N; x++) {
    vector<int> B;
    for (int y = 0; y < N; y++) {
      B.push_back(A[y][x]);
    }
    if (!check(B)) {
      ans = false;
      break;
    }
  }
  // 3x3
  auto f = [&](int y0, int x0) -> vector<int> {
    vector<int> B;
    for (int dy = 0; dy < 3; dy++) {
      int y = y0 + dy; 
      for (int dx = 0; dx < 3; dx++) {
        int x = x0 + dx;
        B.push_back(A.at(y).at(x));
      }
    }
    return B;
  };
  for (int y0 = 0; y0 <= 6; y0 += 3) {
    for (int x0 = 0; x0 <= 6; x0 += 3) {
      vector<int> B = f(y0, x0);
      if (!check(B)) {
        ans = false;
        break;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
