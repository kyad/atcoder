// https://atcoder.jp/contests/abc241/tasks/abc241_f

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

map<int, set<int> > row;
map<int, set<int> > col;

// (y, x)から、direction方向に進んで止まる位置を返す
// direction==0: 右
// direction==1: 上
// direction==2: 左
// direction==3: 下
bool move(pair<int, int> pt, int direction, pair<int, int> &ans) {
  int y = pt.first;
  int x = pt.second;
  if (direction % 2 == 0) {
    ans.first = y;
    if (row.count(y) == 0) {
      return false;
    }
    set<int>::iterator it = row[y].lower_bound(x);
    if (direction == 0) {
      if (it == row[y].end()) {
        return false;
      }
      ans.second = *it - 1;
    } else {
      if (it == row[y].begin()) {
        return false;
      }
      it--;
      ans.second = *it + 1;
    }
  } else {
    if (col.count(x) == 0) {
      return false;
    }
    set<int>::iterator it = col[x].lower_bound(y);
    ans.second = x;
    if (direction == 1) {
      if (it == col[x].begin()) {
        return false;
      }
      it--;
      ans.first = *it + 1;
    } else {
      if (it == col[x].end()) {
        return false;
      }
      ans.first = *it - 1;
    }
  }
  return true;
}

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  int SX, SY;
  cin >> SY >> SX;
  int GX, GY;
  cin >> GY >> GX;
  vector<int> Y(N);
  vector<int> X(N);
  for (int n = 0; n < N; n++) {
    cin >> Y[n] >> X[n];
    row[Y[n]].insert(X[n]);
    col[X[n]].insert(Y[n]);
  }

  // Make points
  vector<pair<int, int> > pt;  // id_to_coord;
  map<pair<int, int>, int> mp;  // coord_to_id;
  mp[make_pair(SY, SX)] = pt.size();
  pt.push_back(make_pair(SY, SX));
  for (int n = 0; n < N; n++) {
    const int dy[4] = { 0, -1, 0, 1 };
    const int dx[4] = { -1, 0, 1, 0 };
    for (int k = 0; k < 4; k++) {
      int ny = Y[n] + dy[k];
      int nx = X[n] + dx[k];
      if (ny <= 0 || ny > H || nx <= 0 || nx > W) {
        continue;
      }
      if (mp.count(make_pair(ny, nx)) > 0) {
        continue;
      }
      mp[make_pair(ny, nx)] = pt.size();
      pt.push_back(make_pair(ny, nx));
    }
  }

  if (mp.count(make_pair(GY, GX)) == 0) {
    cout << -1 <<endl;
    return 0;
  }

  // Make graph
  int M = (int)mp.size();
  vector<vector<int> > graph(M);
  for (int m = 0; m < M; m++) {
    for (int d = 0; d < 4; d++) {
      pair<int, int> pt1;
      bool ret = move(pt[m], d, pt1);
      if (!ret) {
        continue;
      }
      graph[m].push_back(mp[pt1]);
    }
  }

  // BFS
  queue<int> todo;
  vector<int> dist(M, -1);
  dist[0] = 0;
  todo.push(0);
  while (!todo.empty()) {
    int v = todo.front();
    todo.pop();
    for (size_t i = 0; i < graph[v].size(); i++) {
      int x = graph[v][i];
      if (dist[x] < 0) {
        dist[x] = dist[v] + 1;
        todo.push(x);
      }
    }
  }
  cout << dist[mp[make_pair(GY, GX)]] << endl;
  return 0;
}
