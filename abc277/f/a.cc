// https://atcoder.jp/contests/abc277/tasks/abc277_f

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }
template<class T> void chmax(T& a, const T b) { a = max(a, b); }

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > A(H, vector<int>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A.at(y).at(x);
    }
  }
  // row check
  const int INF = 1e6+2;
  vector<pair<int, int> > row;
  for (int y = 0; y < H; y++) {
    int mn = INF;
    int mx = -1;
    for (int x = 0; x < W; x++) {
      if (A[y][x] == 0) {
        continue;
      }
      chmin(mn, A[y][x]);
      chmax(mx, A[y][x]);
    }
    if (mn == INF) {
      continue;
    }
    row.push_back(make_pair(mn, mx));
  }
  sort(row.begin(), row.end());
  int ok = true;
  for (size_t i = 1; i < row.size(); i++) {
    if (row[i - 1].second > row[i].first) {
      ok = false;
    }
  }
  if (!ok) {
    cout << "No" << endl;
    return 0;
  }
  // col check
  // 0, 1, ..., W - 1: main
  // W, ..., W + W * H - 1: fake
  int N = W + H * W;
  vector<vector<int> > graph(N);
  scc_graph graph1(N);
  int id = W;
  for (int y = 0; y < H; y++) {
    map<int, vector<int> > mp;
    for (int x = 0; x < W; x++) {
      int a = A[y][x];
      if (a == 0) {
        continue;
      }
      mp[a].push_back(x);
    }
    int px = -1;  // prev
    for (auto it = mp.begin(); it != mp.end(); it++) {
      vector<int> xs = it->second;
      sort(xs.begin(), xs.end());
      int nx = -1;  // next
      for (int x : xs) {
        if (px >= 0) {
          graph[px].push_back(x);
          graph1.add_edge(px, x);
        }
        if (nx < 0) {
          nx = id++;
          assert(nx < N);
        }
        graph[x].push_back(nx);
        graph1.add_edge(x, nx);
      }
      px = nx;
    }
  }
  vector<vector<int> > scc = graph1.scc();
  cout << ((int)scc.size() == N ? "Yes" : "No") << endl;
  return 0;
}
