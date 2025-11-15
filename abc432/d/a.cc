#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

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
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<tuple<int, int, int, int> > dp;
  dp.push_back(make_tuple(0, X - 1, 0, Y - 1));
  for (int i = 0; i < N; i++) {
    vector<tuple<int, int, int, int> > ndp;
    char C;
    int A, B;
    cin >> C >> A >> B;
    int M = dp.size();
    for (int j = 0; j < M; j++) {
      auto [x0, x1, y0, y1] = dp.at(j);
      if (C == 'X') {
        if (x0 < A && A <= x1) {
          ndp.push_back(make_tuple(x0, A - 1, y0 - B, y1 - B));
          ndp.push_back(make_tuple(A, x1, y0 + B, y1 + B));
        } else if (x1 < A) {
          ndp.push_back(make_tuple(x0, x1, y0 - B, y1 - B));
        } else {
          ndp.push_back(make_tuple(x0, x1, y0 + B, y1 + B));
        }
      } else {
        if (y0 < A && A <= y1) {
          ndp.push_back(make_tuple(x0 - B, x1 - B, y0, A - 1));
          ndp.push_back(make_tuple(x0 + B, x1 + B, A, y1));
        } else if (y1 < A) {
          ndp.push_back(make_tuple(x0 - B, x1 - B, y0, y1));
        } else {
          ndp.push_back(make_tuple(x0 + B, x1 + B, y0, y1));
        }
      }
    }
    swap(dp, ndp);
  }
  int K = dp.size();
  UnionFind uf(K);
  // 接するかチェック
  for (int k = 0; k < K; k++) {
    auto [x0, x1, y0, y1] = dp.at(k);
    for (int l = k + 1; l < K; l++) {
      auto [X0, X1, Y0, Y1] = dp.at(l);
      bool ok = false;
      if ((x1 + 1 == X0) || (X1 + 1 == x0)) {
        if (Y1 < y0 || y1 < Y0) {
        } else {
          ok = true;
        }
      } else if ((y1 + 1 == Y0) || (Y1 + 1 == y0)) {
        if (X1 < x0 || x1 < X0) {
        } else {
          ok = true;
        }
      }
      if (ok) {
        uf.unite(k, l);
      }
    }
  }
  // 面積
  map<int, long long> mp;
  for (int k = 0; k < K; k++) {
    auto [x0, x1, y0, y1] = dp.at(k);
    long long w = x1 - x0 + 1;
    long long h = y1 - y0 + 1;
    long long area = w * h;
    int l = uf.root(k);
    mp[l] += area;
  }

  int L = mp.size();
  vector<long long> ans;
  for (auto [l, area] : mp) {
    ans.push_back(area);
  }
  sort(ans.begin(), ans.end());
  cout << L << endl;
  dump(ans);
  return 0;
}
