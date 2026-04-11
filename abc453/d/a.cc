#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int K = 4;
  const int dy[4] = {0, -1, 0, +1};
  const int dx[4] = {+1, 0, -1, 0};
  const int INF = 1e9;
  vector<vector<vector<int> > > dp(K, vector<vector<int> > (H, vector<int>(W, INF)));
  int sy = -1, sx = -1, gy = -1, gx = -1; 
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) == 'S') {
        sy = y; sx = x;
      } else if (S.at(y).at(x) == 'G') {
        gy = y; gx = x;
      }
    }
  }
  assert(sy >= 0); assert(sx >= 0);
  assert(gy >= 0); assert(gx >= 0);
  queue<tuple<int, int, int> > q;
  for (int k = 0; k < K; k++) {
    dp.at(k).at(sy).at(sx) = 0;
    q.push(make_tuple(sy, sx, k));
  }
  while (!q.empty()) {
    auto [y, x, k] = q.front();
    q.pop();
    for (int nk = 0; nk < K; nk++) {
      if (S.at(y).at(x) == 'o') {
        if (nk != k) continue;
      } else if (S.at(y).at(x) == 'x') {
        if (nk == k) continue;
      }
      int ny = y + dy[nk];
      int nx = x + dx[nk];
      if (ny < 0 || ny >= H || nx < 0 || nx >= W || S.at(ny).at(nx) == '#') {
        continue;
      }
      if (dp.at(nk).at(ny).at(nx) < INF) {
        continue;
      }
      dp.at(nk).at(ny).at(nx) = dp.at(k).at(y).at(x) + 1;
      q.push(make_tuple(ny, nx, nk));
    }
  }
  int gk = -1;
  int dist = INF;
  for (int k = 0; k < K; k++) {
    if (dp.at(k).at(gy).at(gx) < INF) {
      gk = k;
      dist = dp.at(k).at(gy).at(gx);
      break;
    }
  }
  if (gk == -1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << '\n';
  string T;
  int y = gy, x = gx, k = gk;
  string D = "RULD";
  while (dist >= 1) {
    T.push_back(D.at(k));
    int py = y - dy[k];
    int px = x - dx[k];
    assert(0 <= py && py < H);
    assert(0 <= px && px < W);
    int pk = -1;
    for (int l = 0; l < K; l++) {  // l: 1個前のl
      if (S.at(py).at(px) == 'o') {
        if (k != l) continue;
      } else if (S.at(py).at(px) == 'x') {
        if (k == l) continue;
      }
      int ppy = py - dy[l];
      int ppx = px - dx[l];
      if (ppy < 0 || ppy >= H || ppx < 0 || ppx >= W || S.at(ppy).at(ppx) == '#') {
        continue;
      }
      if (dp.at(l).at(py).at(px) == dist - 1) {
        pk = l;
        break;
      }
    }
    assert(pk >= 0);
    y = py;
    x = px;
    k = pk;
    dist--;
  }
  reverse(T.begin(), T.end());
  cout << T << endl;
  return 0;
}
