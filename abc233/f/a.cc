// https://atcoder.jp/contests/abc233/tasks/abc233_f

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;

  UnionFind(int n) : parent(n, -1), _size(n, 1) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      //return root(parent[x]);  // O(logN)
      return parent[x] = root(parent[x]);  // O(alpha(N))
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
    parent[y] = x;
    _size[x] += _size[y];
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }
};


vector<int> P;
vector<vector<int> > graph;
vector<int> deg;
vector<bool> finished;
vector<pair<int, int> > C;
int root;

bool dfs(int u, int parent, int root) {
  if (P[u] == root) {
    return true;
  }
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (finished[v]) {
      continue;
    }
    if (v == parent) {
      continue;
    }
    bool ret = dfs(v, u, root);
    if (ret) {
      C.push_back(make_pair(u, v));
      swap(P[u], P[v]);
      return ret;
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  P.resize(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  UnionFind uf(N);
  int M;
  cin >> M;
  graph.resize(N);
  deg.resize(N, 0);
  map<pair<int, int>, int> mp;
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (uf.unite(a, b)) {
      graph[a].push_back(b);
      deg[a]++;
      graph[b].push_back(a);
      deg[b]++;
      mp[make_pair(min(a, b), max(a, b))] = m;
    }
  }
  queue<int> q;
  for (int n = 0; n < N; n++) {
    if (deg[n] <= 1) {
      q.push(n);
    }
  }
  finished.resize(N, false);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (!dfs(u, -1, u)) {
      cout << -1 << endl;
      return 0;
    }
    finished[u] = true;
    if (deg[u] == 1) {
      for (size_t i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (finished[v]) {
          continue;
        }
        deg[u]--;
        deg[v]--;
        if (deg[v] <= 1) {
          q.push(v);
        }
        break;
      }
    }
  }
  int K = (int) C.size();
  cout << K << endl;
  for (int k = 0; k < K; k++) {
    int a = min(C[k].first, C[k].second);
    int b = max(C[k].first, C[k].second);
    cout << (mp[make_pair(a, b)] + 1);
    if (k != K - 1) {
      cout << ' ';
    }
  }
  cout << endl;
  return 0;
}
