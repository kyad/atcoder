// https://atcoder.jp/contests/joisc2010/tasks/joisc2010_finals
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap11/code_11_1.cpp
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap11/code_11_4.cpp

#include <algorithm>
#include <iostream>
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
  int N, M, K;
  cin >> N >> M >> K;
  vector<tuple<int, int, int> > edges;
  for (int m = 0; m < M; m++) {
    int A, B, C;
    cin >> A >> B >> C;
    edges.push_back(make_tuple(C, A - 1, B - 1));
  }
  int ans = 0;
  int count = 0;
  UnionFind uf(N);
  sort(edges.begin(), edges.end());
  for (size_t e = 0; e < edges.size(); e++) {
    if (N - K == count) {
      break;
    }
    int a = get<1>(edges.at(e));
    int b = get<2>(edges.at(e));
    if (uf.issame(a, b)) {
      continue;
    }
    int c = get<0>(edges.at(e));
    ans += c;
    uf.unite(a, b);
    count++;
  }
  cout << ans << endl;
  return 0;
}
