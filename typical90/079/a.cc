#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<long long> > A(H, vector<long long>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A.at(y).at(x);
    }
  }
  vector<vector<long long> > B(H, vector<long long>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> B.at(y).at(x);
    }
  }
  long long ans = 0;
  for (int y = 0; y <= H - 2; y++) {
    for (int x = 0; x <= W - 2; x++) {
      long long diff = B[y][x] - A[y][x];
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          int ny = y + i;
          int nx = x + j;
          A[ny][nx] += diff;
        }
      }
      ans += abs(diff);
    }
    // check x == W - 1;
    if (B[y][W - 1] != A[y][W - 1]) {
      cout << "No" << endl;
      return 0;
    }
  }
  // check y == H - 1;
  for (int x = 0; x < W; x++) {
    if (B[H - 1][x] != A[H - 1][x]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
  return 0;
}
