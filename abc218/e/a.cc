// https://atcoder.jp/contests/abc218/tasks/abc218_e
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap11/code_11_1.cpp
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap11/code_11_4.cpp
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap15/code_15_1.cpp

#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;

  UnionFind(int n) : parent(n, -1), _size(n, 1) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      //return root(parent[x]);
      return parent[x] = root(parent[x]);
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
  vector<tuple<int, int, int> > edges;
  for (int m = 0; m < M; m++) {
    int A, B, C;
    cin >> A >> B >> C;
    edges.push_back(make_tuple(C, A - 1, B - 1));
  }
  // Kruskal's algorithm O(|E|log|V|)
  sort(edges.begin(), edges.end());
  long long ans = 0LL;
  UnionFind uf(N);
  size_t i = 0;
  for (i = 0; i < edges.size(); i++) {
    int w = get<0>(edges[i]);
    int u = get<1>(edges[i]);
    int v = get<2>(edges[i]);
    if (!uf.unite(u, v)) {
      ans += max(w, 0);
    }
  }
  cout << ans << endl;
  return 0;
}
