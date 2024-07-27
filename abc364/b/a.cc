#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int y, x;
  cin >> y >> x;
  y--; x--;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  string X;
  cin >> X;
  for (char c: X) {
    int dy = 0;
    int dx = 0;
    if (c == 'L') {
      dx = -1;
    } else if (c == 'R') {
      dx = +1;
    } else if (c == 'U') {
      dy = -1;
    } else {
      dy = +1;
    }
    int ny = y + dy;
    int nx = x + dx;
    if (ny < 0 || ny >= H || nx < 0 || nx >= W || C.at(ny).at(nx) == '#') {
      continue;
    }
    y = ny;
    x = nx;
  }
  cout << (y + 1) << ' ' << (x + 1) << endl;
  return 0;
}
