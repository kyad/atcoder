#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W, X, Y;
  cin >> H >> W >> X >> Y;
  X--; Y--;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  string T;
  cin >> T;
  int y = X;
  int x = Y;
  set<pair<int, int> > visited;
  for (char c : T) {
    int dy = 0;
    int dx = 0;
    if (c == 'U') {
      dy = -1;
    } else if (c == 'D') {
      dy = +1;
    } else if (c == 'L') {
      dx = -1;
    } else {
      dx = +1;
    }
    int ny = y + dy;
    int nx = x + dx;
    if (ny < 0 || ny >= H || nx < 0 || nx >= W || S.at(ny).at(nx) == '#') {
      continue;
    }
    if (S.at(ny).at(nx) == '@') {
      visited.insert(make_pair(ny, nx));
    }
    y = ny;
    x = nx;
  }
  int C = visited.size();
  cout << (y + 1) << ' ' << (x + 1) << ' ' << C << endl;
  return 0;
}
