// https://atcoder.jp/contests/abc333/editorial/7948

#include <algorithm>
#include <cassert>
#include <iostream>
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

using Prob = mint;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  cin >> N;
  Prob p =(Prob)(1) / 2;
  vector<Prob> pp(N + 1, 1);  // pp[i] = p^i
  for (int i = 1; i <= N; i++) pp[i] = pp[i - 1] * p;
  vector<Prob> dp(1, 1);  // dp[1][0] = 1
  for (int i = 2; i <= N; i++) {
    vector<Prob> prev(N, 0); swap(dp, prev);
    // x: 先頭が消える確率
    Prob x = p / ((Prob)1 - pp[i]);
    // dp[i][0]
    dp[0] = 0;
    for (int j = 1; j <= i - 1; j++) {
      dp[0] += pp[j] * prev[i - 1 - j];
    }
    dp[0] *= x;
    // dp[i][j], 1<=j<=i-1
    for (int j = 1; j <= i - 1; j++) {
      dp[j] = p * dp[j - 1] + ((Prob)1 - pp[i]) * x * prev[j - 1];
    }
  }
  vector<Prob> ans;
  for (int i = 0; i < N; i++) {
    ans.push_back(dp[i]);
  }
  dumpvec(ans);
  return 0;
}
