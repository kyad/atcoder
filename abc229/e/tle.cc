#include <iostream>
#include <set>
#include <vector>
using namespace std;

// set
template<class T> ostream& operator<<(ostream& os, const set<T> &s) {
  os << '[';
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    os << *it;
    if (it != prev(s.end())) {
      os << ' ';
    }
  }
  os << ']';
  return os;
}
// vector
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) {
  size_t N = v.size();
  int MOD = -1;
  os << '[';
  for (size_t i = 0; i < N; i++) {
    os << v[i];
    if (i == N - 1) {
      continue;
    } else if (MOD > 0 && i % MOD == (MOD - 1)) {
      os << '\n';
    } else {
      os << ' ';
    }
  }
  os << ']';
  return os;
}

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

  bool unite(int x, int y) {  // x is parent
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    }
    // if (_size[x] < _size[y]) {
    //   swap(x, y);  // Union by size
    // }
    parent[y] = x;
    _size[x] += _size[y];
    return true;
  }

  int size(int x) {
    return _size[root(x)];
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
  }
  vector<int> ans(N, 0);
  for (int n = 1; n < N; n++) {
    UnionFind uf(N);
    for (int u = n; u < N; u++) {
      for (size_t i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        uf.unite(u, v);
      }
    }
    set<int> st;
    for (int u = n; u < N; u++) {
      st.insert(uf.root(u));
    }
    ans.at(n - 1) = (int)st.size();
  }
  for (int n = 0; n < N; n++) {
    cout << ans[n] << endl;
  }
  return 0;
}
