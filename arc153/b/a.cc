#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int y = 0; y < H; y++) {
    cin >> A.at(y);
  }
  int Q;
  cin >> Q;
  // sim
  int y = 0;
  int x = 0;
  for (int q = 0; q < Q; q++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    // sim y
    if (y <= a) {
      y = a - y;
    } else {
      y = H - y + a;
    }
    assert(0 <= y && y < H);
    // sim x
    if (x <= b) {
      x = b - x;
    } else {
      x = W - x + b;
    }
    assert(0 <= x && x < W);
  }
  vector<string> ans(A);
  int sign = (Q % 2 == 0) ? 1 : -1;
  for (int i = 0; i < H; i++) {
    int ny = (sign * i + y + H) % H;
    for (int j = 0; j < W; j++) {
      int nx = (sign * j + x + W) % W;
      ans[ny][nx] = A[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    cout << ans.at(i) << endl;
  }
  return 0;
}
