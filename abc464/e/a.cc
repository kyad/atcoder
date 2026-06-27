#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
  int H, W, Q;
  cin >> H >> W >> Q;
  bool sw = false;
  if (W < H) {
    swap(W, H);  // H < Wにする
    sw = true;
  }
  vector<int> R(Q), C(Q);
  vector<char> X(Q);
  for (int qi = 0; qi < Q; qi++) {
    cin >> R.at(qi) >> C.at(qi) >> X.at(qi);
  }
  if (sw) {
    swap(R, C);
  }
  vector<string> S(H, string(W, 'A'));
  vector<int> fx(H, -1);
  for (int qi = Q - 1; qi >= 0; qi--) {
    int r = R.at(qi) - 1;
    int c = C.at(qi) - 1;
    for (int y = 0; y <= r; y++) {
      if (c <= fx.at(y)) {
        continue;
      }
      for (int x = fx.at(y) + 1; x <= c; x++) {
        S.at(y).at(x) = X.at(qi);
      }
      fx.at(y) = c;
    }
  }
  if (sw) {
    for (int y = 0; y < W; y++) {
      for (int x = 0; x < H; x++) {
        cout << S.at(x).at(y);
      }
      cout << '\n';
    }
  } else {
    for (int y = 0; y < H; y++) {
      cout << S.at(y) << '\n';
    }
  }
  return 0;
}
