// https://www.youtube.com/watch?v=ugeZCP6JxqQ&t=9393s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

// 重み付きUnionFind (ポテンシャル付きUnionFind)
template<class T> struct WeightedUnionFind {
  vector<int> parent, _size;
  vector<T> _diff;  // 重み。親とのdiff。もしくは、ポテンシャル。親との高さの差
  int _num_unions;

  WeightedUnionFind(int n) : parent(n, -1), _size(n, 1), _diff(n, 0), _num_unions(n) {}

  int root(int x) {
    if (parent[x] == -1) {
      return x;
    } else {
      int z = parent[x];
      parent[x] = root(z);  // 経路圧縮。経路圧縮しない場合はWeight計算が誤る
      _diff[x] += _diff[z];  // この時点では、parent[x]も経路圧縮によって親がrootになっているため
      return parent[x];
    }
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  // 第三引数を設定すると、Weight[x] - Weight[y] = dになるようにする
  // 返り値: 矛盾なくmergeできた場合true、矛盾が生じた場合はfalseでmergeしない。
  bool merge(int x, int y, T d) {
    // 経路圧縮する
    int root_x = root(x);
    int root_y = root(y);
    // この時、x, yは親がrootなので、Weight[x] = diff[x], Weight[y] = diff[y]となる
    if (root_x == root_y) {  // 親が同じ時
      // _diff[x] + d == _diff[y]であれば、矛盾無くmergeできる。
      return (_diff[x] + d == _diff[y]);
    }
    // 親が違う時
#if 1
    // Union by size
    // 実施する場合 計算量O(alpha(N))
    // 実施しない場合 計算量O(logN)
    if (_size[root_x] < _size[root_y]) {
      swap(root_x, root_y);
      swap(x, y);
      d *= -1;
    }
#endif
    parent[root_y] = root_x;  // 親はx
    _size[root_x] += _size[root_y];
    _diff[root_y] = _diff[x] + d - _diff[y];
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
  int N, Q;
  cin >> N >> Q;
  vector<int> ans;
  WeightedUnionFind<long long> uf(N);
  for (int q = 1; q <= Q; q++) {
    int A, B;
    long long D;
    cin >> A >> B >> D;
    A--; B--;
    if (uf.merge(A, B, D)) {
      ans.push_back(q);
    }
  }
  dumpvec(ans);
  return 0;
}
