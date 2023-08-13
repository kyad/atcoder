#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {}

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
    _num_unions--;
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }

  int num_unions() {  // unionの数(ひとまとまりになっているグループの数)を返す
    return _num_unions;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, char> > edges(M);  // a, b, c
  for (int m = 0; m < M; m++) {
    int a, b;
    char c;
    cin >> a >> b >> c;
    a--; b--;
    get<0>(edges.at(m)) = a;
    get<1>(edges.at(m)) = b;
    get<2>(edges.at(m)) = c;
  }
  string S;
  cin >> S;
  // 両端ともOKになるノード
  queue<int> q;
  // 各uで、S[u]!=cかつ相方の色がcのエッジ
  vector<vector<int> > es(N);
  for (int m = 0; m < M; m++) {
    int a = get<0>(edges.at(m));
    int b = get<1>(edges.at(m));
    char c = get<2>(edges.at(m));
    // qに追加可能か
    if (S[a] == c && S[b] == c) {
      q.push(m);
    }
    // a-->b
    if (S[a] != c && S[b] == c) {
      es[a].push_back(m);
    }
    // b-->a
    if (S[b] != c && S[a] == c) {
      es[b].push_back(m);
    }
  }

  // Kruskal's algorithm O(|E|log|V|)
  UnionFind uf(N);
  vector<int> ans;
  vector<bool> used(M, false);
  vector<bool> pushed_u(N, false);
  vector<bool> ok(N, false);
  while (!q.empty()) {
    const int m = q.front();
    const int a = get<0>(edges.at(m));
    const int b = get<1>(edges.at(m));
    //const char c = get<2>(edges.at(m));
    q.pop();
    if (used[m]) {
      continue;
    }
    if (uf.issame(a, b)) {
      continue;
    }
    uf.unite(a, b);
    ok[a] = true;
    ok[b] = true;
    if (!pushed_u[a]) {
      for (int e : es[a]) {
        q.push(e);
      }
      pushed_u[a] = true;
    }
    if (!pushed_u[b]) {
      for (int e : es[b]) {
        q.push(e);
      }
      pushed_u[b] = true;
    }
    used[m] = true;
    ans.push_back(m + 1);
  }

  
  // 残りは何でも良い
  for (int m = 0; m < M; m++) {
    const int a = get<0>(edges.at(m));
    const int b = get<1>(edges.at(m));
    const char c = get<2>(edges.at(m));
    if (used[m]) {
      continue;
    }
    if (uf.issame(a, b)) {
      continue;
    }
#if 1
    // 念の為
    if (S[a] == c) {
      ok[a] = true;
    }
    if (S[b] == c) {
      ok[b] = true;
    }
#endif
    uf.unite(a, b);
    used[m] = true;
    ans.push_back(m + 1);
  }

  for (int u = 0; u < N; u++) {
    if (ok[u] == false) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  dumpvec(ans);

  return 0;
}
