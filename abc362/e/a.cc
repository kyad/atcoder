#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  set<long long> ds;  // 公差
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      long long d = A.at(j) - A.at(i);
      ds.insert(d);
    }
  }
  vector<map<long long, vector<int> > > nis(N, map<long long, vector<int> >());  // nis[i][d]: iからスタートして公差dのni達
  for (int d : ds) {
    for (int i = N - 1; i >= 0; i--) {
      for (int ni = i + 1; ni < N; ni++) {
        if (A.at(i) + d == A.at(ni)) {
          nis[i][d].push_back(ni);
        }
      }
    }
  }
  vector<mint> ans(N + 1, 0);
  ans[1] = N;  // 以降は長さ>=2を考える
  for (int d : ds) {  // dを固定する
    vector<vector<mint> > dp(N, vector<mint>(N + 1, 0));  // dp[i][j]: iスタートで長さjの等差数列の個数
    dp[N - 1][0] = 1;
    for (int i = N - 2; i >= 0; i--) {
      for (int ni : nis[i][d]) {
        dp[i][2]++;
        for (int j = 3; j <= N; j++) {
          dp[i][j] += dp[ni][j - 1];
        }
      }
    }
    for (int j = 2; j <= N; j++) {
      for (int i = 0; i < N; i++) {
        ans[j] += dp[i][j];
      }
    }
  }
 
  dump(ans, 1);
  return 0;
}
