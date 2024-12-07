#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  // UnonFindが範囲の時の左端と右端
  vector<int> _left;
  vector<int> _right;
  // 追加
  vector<int> _nA;
  vector<int> _nB;

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    _left.resize(n, 0);
    _right.resize(n, 0);
    for (int i = 0; i < n; i++) {
      _left.at(i) = i;
      _right.at(i) = i;
    }
    // 追加
    _nA.resize(n, 0);
    _nB.resize(n, 0);
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

  int unite(int x, int y) {  // min(nA, nB)を返す
    x = root(x);
    y = root(y);
    if (x == y) {
      return 0;  // 何も起こらない
    }
    if (_size[x] < _size[y]) {
      swap(x, y);  // Union by size
    }
    // xが新しい親
    parent[y] = x;
    _size[x] += _size[y];
    _num_unions--;

    // 範囲の更新
    int nleft = min(_left.at(x), _left.at(y));
    _left.at(x) = nleft;
    int nright = max(_right.at(x), _right.at(y));
    _right.at(x) = nright;
    // 追加
    _nA.at(x) += _nA.at(y);
    _nB.at(x) += _nB.at(y);

    int count = min(_nA.at(x), _nB.at(x));
    _nA.at(x) -= count;
    _nB.at(x) -= count;
    
    return count;
  }

  int size(int x) {
    return _size[root(x)];
  }

  int num_unions() {  // unionの数(ひとまとまりになっているグループの数)を返す
    return _num_unions;
  }

  int left(int x) {
    return _left[root(x)];
  }

  int right(int x) {
    return _right[root(x)];
  }

  void addA(int u, int value) {
    _nA.at(u) += value;
  }

  void addB(int u, int value) {
    _nB.at(u) += value;
  }
};


int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<int, pair<int, int> > > edges(M);
  for (int j = 0; j < M; j++) {
    int U, V, W;
    cin >> U >> V >> W;
    U--; V--;
    edges.at(j) = make_pair(W, make_pair(U, V));
  }

  UnionFind uf(N);
  // A
  for (int k = 0; k < K; k++) {
    int uA;
    cin >> uA;
    uA--;
    uf.addA(uA, 1);
  }
  // B
  for (int k = 0; k < K; k++) {
    int uB;
    cin >> uB;
    uB--;
    uf.addB(uB, 1);
  }

  // Kruskal's algorithm O(|E|log|V|)
  sort(edges.begin(), edges.end());
  long long ans = 0;
  for (size_t i = 0; i < edges.size(); i++) {
    int w = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (uf.issame(u, v)) {
      continue;
    }
    int count = uf.unite(u, v);
    long long now = ((long long)w) * count;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
