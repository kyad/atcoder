#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  string T;
  cin >> T;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  auto f = [&](int sy, int sx) -> bool {
    if (S[sy][sx] == '#') {
      return false;
    }
    int y = sy;
    int x = sx;
    for (int n = 0; n < N; n++) {
      int dx = 0, dy = 0;
      if (T[n] == 'L') { dx--; }
      else if (T[n] == 'R') { dx++; }
      else if (T[n] == 'U') { dy--; }
      else { dy++; }
      int nx = x + dx;
      int ny = y + dy;
      if (nx < 0 || nx >= W || ny < 0 || ny >= H || S[ny][nx] == '#') {
        return false;
      }
      y = ny;
      x = nx;
    }
    return true;
  };
  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (f(y, x)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
