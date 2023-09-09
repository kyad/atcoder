#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool check(int a, int b, int c) {
  int count = 0;
  if (a < 0) {
    count++;
  }
  if (b < 0) {
    count++;
  }
  if (c < 0) {
    count++;
  }
  if (count != 1) {
    return true;
  }
  if (a == -1) {
    if (b == c) {
      return false;
    }
  } else if (b == -1) {
    if (a == c) {
      return false;
    }
  } else if (c == -1) {
    if (a == b) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<vector<int> > C(3, vector<int>(3, 0));
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 3; x++) {
      cin >> C.at(y).at(x);
    }
  }
  vector<int> P(9);
  for (int i = 0; i < 9; i++) {
    P[i] = i;
  }
  int oks = 0;
  do {
    bool ok = true;
    // シミュレーション
    vector<vector<int> > A(3, vector<int>(3, -1));
    for (int i = 0; i < 9; i++) {
      // decode
      int y = P[i] / 3;
      int x = P[i] % 3;
      // 縦
      if (!check(A[0][x], A[1][x], A[2][x])) {
        ok = false;
        break;
      }
      // 横
      if (!check(A[y][0], A[y][1], A[y][2])) {
        ok = false;
        break;
      }
      // 斜め1
      if (x == y) {
        if (!check(A[0][0], A[1][1], A[2][2])) {
          ok = false;
          break;
        }
      }
      // 斜め2
      if (x + y == 2) {
        if (!check(A[0][2], A[1][1], A[2][0])) {
          ok = false;
          break;
        }
      }
      A[y][x] = C[y][x];
    }
    if (ok) {
      oks++;
    }
  } while (next_permutation(P.begin(), P.end()));
  double ans = (double)oks / 362880;
  cout << setprecision(15) << ans << endl;
  return 0;
}
