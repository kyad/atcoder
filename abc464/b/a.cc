#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  vector<int> X(W), Y(H);
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (C.at(y).at(x) == '#') {
        Y.at(y)++;
        X.at(x)++;
      }
    }
  }
  int l = 0, r = W - 1;
  int t = 0, b = H - 1;
  while (true) {
    if (X.at(l) == 0) {
      l++;
    } else {
      break;
    }
  }
  while (true) {
    if (X.at(r) == 0) {
      r--;
    } else {
      break;
    }
  }
  while (true) {
    if (Y.at(t) == 0) {
      t++;
    } else {
      break;
    }
  }
  while (true) {
    if (Y.at(b) == 0) {
      b--;
    } else {
      break;
    }
  }
  for (int y = t; y <= b; y++) {
    for (int x = l; x <= r; x++) {
      cout << C.at(y).at(x);
    }
    cout << '\n';
  }
  return 0;
}
