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
  int H, W;
  cin >> H >> W;
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  vector<vector<int>> ans(H, vector<int>(W, 0));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny >= 0 && nx >= 0 && ny < H && nx < W) {
          ans.at(y).at(x)++;
        }
      }
    }
  }
  for (int y = 0; y < H; y++) {
    dump(ans.at(y));
  }
  return 0;
}
