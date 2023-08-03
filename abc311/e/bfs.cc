#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H;
  int W;
  int N;
  cin >> H >> W >> N;
  // BFS
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(H, vector<int>(W, -1));
  for (int n = 0; n < N; n++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    dist.at(a).at(b) = 0;
    todo.push(make_pair(a, b));
  }
  const int dy[3] = {-1, 0, -1};
  const int dx[3] = {0, -1, -1};
  while (!todo.empty()) {
    int y = todo.front().first;
    int x = todo.front().second;
    todo.pop();
    for (int k = 0; k < 3; k++) {
      const int ny = y + dy[k];
      const int nx = x + dx[k];
      if (ny < 0 || nx < 0) {
        continue;
      }
      if (dist.at(ny).at(nx) < 0) {
        dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
        todo.push(make_pair(ny, nx));
      }
    }
  }
  long long ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int now;
      const int mx = min(H - y, W - x);
      if (dist.at(y).at(x) < 0) {
        now = mx;
      } else {
        now = min(mx, dist.at(y).at(x));
      }
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
