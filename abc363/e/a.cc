#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int H, W, Y;
  cin >> H >> W >> Y;
  vector<vector<int> > A(H, vector<int>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A.at(y).at(x);
    }
  }
  // 海に面している所(高さ, (y, x))
  priority_queue<pair<int, pair<int, int> > , vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
  // 初期値
  for (int y = 0; y < H; y++) {
    pq.push(make_pair(A.at(y).at(0), make_pair(y, 0)));
    pq.push(make_pair(A.at(y).at(W - 1), make_pair(y, W - 1)));
  }
  for (int x = 0; x < W; x++) {
    pq.push(make_pair(A.at(0).at(x), make_pair(0, x)));
    pq.push(make_pair(A.at(H - 1).at(x), make_pair(H - 1, x)));
  }

  int ans = H * W;
  vector<vector<bool> > sea(H, vector<bool>(W, false));
  const int dy[4] = {0, -1, 0, 1};
  const int dx[4] = {-1, 0, 1, 0};
  for (int y = 1; y <= Y; y++) {
    // 沈める
    while (!pq.empty()) {
      int h = pq.top().first;
      if (h > y) {
        break;
      }
      int y = pq.top().second.first;
      int x = pq.top().second.second;
      pq.pop();
      if (sea[y][x]) {
        continue;
      }
      ans--;
      sea[y][x] = true;
      for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || sea[ny][nx]) {
          continue;
        }
        pq.push(make_pair(A[ny][nx], make_pair(ny, nx)));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
