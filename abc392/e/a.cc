#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
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
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int j = 0; j < M; j++) {
    cin >> A.at(j) >> B.at(j);
    A.at(j)--; B.at(j)--;
  }
  vector<int> used(M, false);  // ケーブルjを使ったか
  UnionFind uf(N);
  for (int j = 0; j < M; j++) {
    if (uf.issame(A.at(j), B.at(j))) {
      continue;
    }
    uf.unite(A.at(j), B.at(j));
    used.at(j) = true;
  }

  vector<int> roots;
  for (int i = 0; i < N; i++) {
    // root以外は飛ばす
    if (i != uf.root(i)) {
      continue;
    }
    // iはroot
    roots.push_back(i);
  }

  vector<vector<int> > cables(N);  // cables[i]: ルートiが持つケーブルの番号達
  for (int j = 0; j < M; j++) {
    if (used.at(j)) {
      continue;
    }
    assert(uf.issame(A.at(j), B.at(j)));
    int i = uf.root(A.at(j));
    cables.at(i).push_back(j);
  }

  set<pair<int, int> > st;  // (余りのケーブルの個数、rootの番号)
  for (int i : roots) {
    st.insert(make_pair(cables.at(i).size(), i));
  }

  vector<tuple<int, int, int> > ans;
  while (st.size() >= 2) {
    // uの余りからvにつなぎかえる
    int u = prev(st.end())->second;
    int u_cables = prev(st.end())->first;
    int v = st.begin()->second;

    assert(u_cables >= 1);
    assert(u_cables == (int)cables.at(u).size());
    int j = cables.at(u).back();  // 使うケーブルは末端
    cables.at(u).pop_back();

    ans.push_back(make_tuple(j + 1, A.at(j) + 1, v + 1));

    // vのケーブルをuにマージする
    for (int j : cables.at(v)) {
      cables.at(u).push_back(j);
    }
    // vを削除する(マージされたので削除)
    st.erase(st.begin());

    // uの情報を更新する
    st.erase(prev(st.end()));
    st.insert(make_pair((int)cables.at(u).size(), u));
  }
    
  int K = ans.size();
  cout << K << endl;
  for (int k = 0; k < K; k++) {
    cout << get<0>(ans.at(k)) << ' ' << get<1>(ans.at(k)) << ' ' << get<2>(ans.at(k)) << '\n';
  }
  return 0;
}
