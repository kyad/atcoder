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
  vector<vector<bool>> vis(H, vector<bool>(W, false));
  int y = 0;
  int x = 0;
  int ans = 0;
  while (true) {
    if (vis.at(y).at(x)) {
      cout << -1 << endl;
      exit(0);
    }
    vis.at(y).at(x) = true;
    int dy = 0, dx = 0;
    if (C.at(y).at(x) == 'U') {
      dy = -1;
    } else if (C.at(y).at(x) == 'D') {
      dy = 1;
    } else if (C.at(y).at(x) == 'L') {
      dx = -1;
    } else {
      dx = 1;
    }
    int ny = y + dy;
    int nx = x + dx;
    if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
      break;
    }
    y = ny;
    x = nx;
    ans++;
  }
  cout << ans << '\n';
  return 0;
}
