#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> G(H);
  for (int y = 0; y < H; y++) {
    cin >> G.at(y);
  }
  vector<vector<int> > S(H, vector<int>(26, 0));  // S[y][c]: 縦の数
  vector<vector<int> > T(W, vector<int>(26, 0));  // T[x][c]: 横の数
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int c = G.at(y).at(x) - 'a';
      S.at(y).at(c)++;
      T.at(x).at(c)++;
    }
  }
  auto check = [&](int y, int x) -> bool {
    int c = G.at(y).at(x) - 'a';
    if (S.at(y).at(c) == 1 && T.at(x).at(c) == 1) {
      return true;
    } else {
      return false;
    }
  };
  string ans;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (check(y, x)) {
        ans += G.at(y).at(x);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
