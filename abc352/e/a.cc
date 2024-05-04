#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

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
  vector<pair<long long, vector<int> > > As;
  for (int m = 0; m < M; m++) {
    int K;
    long long C;
    cin >> K >> C;
    vector<int> A(K);
    for (int k = 0; k < K; k++) {
      cin >> A.at(k);
      A.at(k)--;
    }
    As.push_back(make_pair(C, A));
  }
  sort(As.begin(), As.end());
  UnionFind uf(N);
  long long ans = 0;
  for (int m = 0; m < M; m++) {
    long long cost = As.at(m).first;
    int K = As.at(m).second.size();
    for (int k = K - 2; k >= 0; k--) {
      int &u = As.at(m).second.at(k);
      int &v = As.at(m).second.at(k + 1);
      if (uf.issame(u, v)) {
        continue;
      }
      ans += cost;
      uf.unite(u, v);
    }
  }
  if (uf.num_unions() != 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
