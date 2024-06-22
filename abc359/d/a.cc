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

bool is_pendrome(int s, int K) {
  string S;
  for (int k = 0; k < K; k++) {
    if (s % 2 == 1) {
      S.push_back('B');
    } else {
      S.push_back('A');
    }
    s /= 2;
  }
  string T(S);
  reverse(T.begin(), T.end());
  bool ans = (S == T);
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');  // 冒頭に0を挿入する 1-indexedにするため
  int K2 = 1<<K;
  // dp[i][s]: iまで見た時に末尾のK文字がsの時の回文を含まない個数
  int mask = (1<<(K-1)) - 1;

  vector<vector<mint> > dp(N + 1, vector<mint>(K2, 0));
  dp[0][0] = 1;
  // 回文か
  vector<bool> is_pend(K2, false);
  for (int s = 0; s < K2; s++) {
    is_pend.at(s) = is_pendrome(s, K);
  }
  for (int i = 1; i <= N; i++) {
    for (int ps = 0; ps < K2; ps++) {
      for (int c = 0; c < 2; c++) {  // i個目にA(0), B(1)のどっちを置くか
        if (S.at(i) == 'A' && c == 1) continue;
        if (S.at(i) == 'B' && c == 0) continue;
        int s = ((ps & mask) << 1) + c;  // 今iの状態
        dp[i][s] += dp[i - 1][ps];
        if (i >= K && is_pend.at(s)) {  // 回文ならダメ
          dp[i][s] = 0;
        }
      }
    }
  }
  mint ans = 0;
  for (int s = 0; s < K2; s++) {
    ans += dp[N][s];
  }
  cout << ans << endl;
  return 0;
}
