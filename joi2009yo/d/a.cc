// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d

#include <iostream>
#include <vector>
using namespace std;

int rec(vector<vector<int> > map, int y, int x, int depth) {
  size_t h = map.size();
  size_t w = map[0].size();
  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, -1, 0, 1};
  map[y][x] = 0;
  int ans = depth + 1;
  for (int k = 0; k < 4; k++) {
    int ny = y + dy[k];
    int nx = x + dx[k];
    if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
      continue;
    }
    if (!map[ny][nx]) {
      continue;
    }
    ans = max(ans, rec(map, ny, nx, depth + 1));
  }
  return ans;
}

int main() {
  int m, n;
  cin >> m;
  cin >> n;
  vector<vector<int> > map(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  int ans = 0;
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      if (!map[y][x]) {
        continue;
      }
      int depth = rec(map, y, x, 0);
      ans = max(ans, depth);
    }
  }
  cout << ans << endl;
  return 0;
}
