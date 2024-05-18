// https://atcoder.jp/contests/abc354/editorial/10034

#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  int N2 = 1<<N;
  // dp[s]: 状態sから初めて先手が勝つなら1、負けるなら0
  vector<int> dp(N2, -1);
  dp[0] = 0;
  for (int s = 0; s < N2; s++) {
    // sからの遷移先を調べる
    dp[s] = 0;  // 基本負け
    for (int i = 0; i < N; i++) {
      if ((s>>i&1) == 0) {
        continue;
      }
      for (int j = i + 1; j < N; j++) {
        if ((s>>j&1) == 0) {
          continue;
        }
        if (A[i] != A[j] && B[i] != B[j]) {
          continue;
        }
        int ns = s ^ (1<<i) ^ (1<<j);  // 遷移先
        assert(ns < s);
        // 遷移先に負けが1つでも有れば勝ち
        if (dp[ns] == 0) {
          dp[s] = 1;
        }
      }
    }
  }
  string ans = dp[N2 - 1] == 1 ? "Takahashi" : "Aoki";
  cout << ans << endl;
  return 0;
}
