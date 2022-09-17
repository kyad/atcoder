#include <algorithm>
#include <iostream>
#include <map>
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

/**
 * 集合Aと集合Bの共通部分を求める。
 * AとBは事前にソートされていること。
 * AとBはそれぞれ重複要素を持たないこと。
 * 計算量: O(min(|A|, |B|) * log_2(max(|A|, |B|))
 */
template<class T> vector<T> intersection(vector<T> A, vector<T> B) {
  vector<T> ans;
  if (A.size() > B.size()) {
    swap(A, B);
  }
  // |A| <= |B|
  for (size_t i = 0; i < A.size(); i++) {
    T a = A.at(i);
    if (binary_search(B.begin(), B.end(), a)) {
      ans.push_back(a);
    }
  }
  return ans;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int> > G(N);
  for (int u = 1; u <= N - 1; u++) {
    int P;
    cin >> P;
    P--;
    G[P].push_back(u);
  }
  for (int u = 0; u < N; u++) {
    sort(G[u].begin(), G[u].end());
  }

  for (int q = 0; q < Q; q++) {
    int M;
    cin >> M;
    vector<int> S(M);
    for (int m = 0; m < M; m++) {
      cin >> S.at(m);
      S.at(m)--;
    }
    sort(S.begin(), S.end());
    vector<vector<int> > H(N);
    for (int m = 0; m < M; m++) {
      H[S[m]] = intersection(G[S[m]], S);
    }
    UnionFind uf(N);
    for (auto s : S) {
      for (auto v : H[s]) {
        uf.unite(s, v);
      }
    }
    // root -> nodes
    map<int, vector<int> > mp;
    for (int m = 0; m < M; m++) {
      int s = S[m];
      int root = uf.root(s);
      mp[root].push_back(s);
    }
    int ans = 0;
    for (auto [root, vs] : mp) {
      int now = 1;
      for (auto v : vs) {
        now += G[v].size();
      }
      now -= (vs.size() - 1);
      ans += now;
    }
    cout << ans << endl;
  }
  return 0;
}
