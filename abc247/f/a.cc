#include <iostream>
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

int main() {
  const int MOD = 998244353;
  vector<vector<long long> > dp0(200001, vector<long long>(2, 0));
  vector<vector<long long> > dp1(200001, vector<long long>(2, 0));
  // dp0[i][j]: i個目まで見た時にi個目を使う(j=1)/使わない(j=0)場合の数で、1個目を使わないもの。
  dp0[1][0] = 1;
  dp0[1][1] = 0;
  for (int n = 2; n <= 200000; n++) {
    dp0[n][0] = dp0[n - 1][1];
    dp0[n][1] = (dp0[n - 1][0] + dp0[n - 1][1]) % MOD;
  }
  // dp1[i][j]: i個目まで見た時にi個目を使う(j=1)/使わない(j=0)場合の数で、1個目を使うもの。
  dp1[1][0] = 0;
  dp1[1][1] = 1;
  for (int n = 2; n <= 200000; n++) {
    dp1[n][0] = dp1[n - 1][1];
    dp1[n][1] = (dp1[n - 1][0] + dp1[n - 1][1]) % MOD;
  }
#if 0
  cout<< "dp0="<<endl;
  for (int i = 1; i <= 4; i++) {
    cout << dp0[i][0] << " " << dp0[i][1]<<endl;
  }
  cout<< "dp1="<<endl;
  for (int i = 1; i <= 4; i++) {
    cout << dp1[i][0] << " " << dp1[i][1]<<endl;
  }
#endif
  vector<long long> count(200001, 0);
  for (int n = 1; n <= 200000; n++) {
    // ここでdp0[n][0]は足せないけどdp1[n][0]は足せるので、dp0とdp1を場合分けする必要がある。
    count[n] += dp0[n][1];
    count[n] %= MOD;
    count[n] += dp1[n][0];
    count[n] %= MOD;
    count[n] += dp1[n][1];
    count[n] %= MOD;
  }
#if 0
  cout<< "count0="<<endl;
  for (int i = 1; i <= 4; i++) {
    cout << count[i]<<endl;
  }
#endif
  int N;
  cin >> N;
  UnionFind uf(N);
  vector<int> P(N), Q(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  for (int n = 0; n < N; n++) {
    cin >> Q.at(n);
    Q.at(n)--;
  }
  for (int n = 0; n < N; n++) {
    uf.unite(P.at(n), Q.at(n));
  }
  long long ans = 1;
  for (int n = 0; n < N; n++) {
    if (uf.root(n) == n) {
      ans *= count[uf.size(n)];
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
