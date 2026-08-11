// https://atcoder.jp/contests/awc0132/editorial/24134

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> parent, _size;
  int _num_unions;
  // UnonFindが範囲の時の左端と右端
  vector<int> _left;
  vector<int> _right;
  // 追加

  UnionFind(int n) : parent(n, -1), _size(n, 1), _num_unions(n) {
    _left.resize(n, 0);
    _right.resize(n, 0);
    for (int i = 0; i < n; i++) {
      _left.at(i) = i;
      _right.at(i) = i;
    }
    // 追加
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

    return true;
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
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
  }
  int M = *max_element(W.begin(), W.end());
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < N; i++) {
    mp[W.at(i)].push_back(i);
  }
  UnionFind uf(N);
  for (auto [W, is] : mp) {
    if (W >= K) {
      for (size_t i = 1; i < is.size(); i++) {
        uf.unite(is.at(0), is.at(i));
      }
    }
  }
  for (int k = K; k <= M; k++) {
    int prev = -1;
    for (int l = k; l <= M; l += k) {
      if (!mp.contains(l)) {
        continue;
      }
      if (prev == -1) {
        prev = mp[l].at(0);
        continue;
      }
      uf.unite(prev, mp[l].at(0));
    }
  }
  vector<long long> sum(N, 0);
  for (int i = 0; i < N; i++) {
    int root = uf.root(i);
    sum.at(root) += W.at(i);
  }
  long long ans = *max_element(sum.begin(), sum.end());
  cout << ans << '\n';
  return 0;
}
