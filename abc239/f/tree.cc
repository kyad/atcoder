// https://atcoder.jp/contests/abc239/tasks/abc239_f

#include <iostream>
#include <set>
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

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> D(N);
  for (int n = 0; n < N; n++) {
    cin >> D.at(n);
  }
  UnionFind uf(N);
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (!uf.unite(a, b)) {
      // loop
      cout << -1 << endl;
      return 0;
    }
    D[a]--;
    D[b]--;
  }
  int sum = 0;
  int cnt = 0;
  vector<vector<int> > es(N);
  for (int n = 0; n < N; n++) {
    if (D[n] < 0) {
      cout << -1 << endl;
      return 0;
    }
    for (int d = 0; d < D[n]; d++) {
      es[uf.root(n)].push_back(n);
    }
    sum += D[n];
    if (n == uf.root(n)) {
      cnt++;
    }
  }
  if (sum != 2 * (cnt - 1)) {
    cout << -1 << endl;
    return 0;
  }
  set<pair<int, int> > st;
  for (int n = 0; n < N; n++) {
    if (n == uf.root(n)) {
      if (es[n].size() == 0) {
        cout << -1 << endl;
        return 0;
      }
      st.insert(make_pair(es[n].size(), n));
    }
  }
  while (st.size() >= 2) {
    int a = st.begin()->second;
    st.erase(st.begin());
    set<pair<int, int> >::iterator it = st.end();
    it--;
    int b = it->second;
    st.erase(it);
    int p = es[a].back();
    es[a].pop_back();
    int q = es[b].back();
    es[b].pop_back();
    cout << (p + 1) << ' ' <<  (q + 1) << endl;
    // merge tech b <-- a
    es[b].insert(es[b].end(), es[a].begin(), es[a].end());
    st.insert(make_pair(es[b].size(), b));
  }
  return 0;
}
