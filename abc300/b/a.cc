#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<string> rot(vector<string> A, int s, int t, int H, int W) {
  vector<string> C(A);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      C[y][x] = A[(y + s) % H][(x + t) % W];
    }
  }
  return C;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H), B(H);
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
  }
  for (int y = 0; y < H; y++) {
    cin >> B.at(y);
  }
  bool ans = false;
  for (int s = 0; s < H; s++) {
    for (int t = 0; t < W; t++) {
      vector<string> C = rot(A, s, t, H, W);
      if (C == B) {
        ans = true;
        break;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
