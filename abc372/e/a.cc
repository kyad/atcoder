#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  vector<vector<int> > nodes;

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    nodes.resize(n, vector<int>(10, -1));
    for (int i = 0; i < n; i++) {
      nodes.at(i).at(0) = i;
    }
  }

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

    // 追加
    vector<int> merged;
    for (int node : nodes[x]) {
      merged.push_back(node);
    }
    for (int node : nodes[y]) {
      merged.push_back(node);
    }
    sort(merged.begin(), merged.end());
    reverse(merged.begin(), merged.end());
    for (int i = 0; i < 10; i++) {
      nodes[x].at(i) = merged.at(i);
    }

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
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N);
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int U, V;
      cin >> U >> V;
      U--; V--;
      uf.unite(U, V);
    } else {      int V, K;
      cin >> V >> K;
      V--; K--;
      int root = uf.root(V);
      int ans = uf.nodes.at(root).at(K);
      if (ans >= 0) {
        ans++;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
