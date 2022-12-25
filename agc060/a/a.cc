#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

bool check(char a, char b, char c) {
  set<char> st;
  int exp = 3;
  if (a == '?') {
    exp--;
  } else {
    st.insert(a);
  }
  if (b == '?') {
    exp--;
  } else {
    st.insert(b);
  }
  if (c == '?') {
    exp--;
  } else {
    st.insert(c);
  }
  return ((int)(st.size()) == exp);
}

bool check_fast(char a, char b, char c) {
  if (a == b || b == c || c == a) {
    return false;
  } else {
    return true;
  }    
}

#define ALPHABET (26)

void naive(int N, string S) {
  mint ans = 0;
  auto check2 = [&](string T) -> bool {
    T = '_' + T;
    // sum[i][c]: [0, i](1-indexed)のcの個数
    vector<vector<int> > sum(N + 1, vector<int>(ALPHABET, 0));
    // count[i][j][c]: [i, j](1-indexed)のcの個数
    vector<vector<vector<int> > > count(N + 1, vector<vector<int> > (N + 1, vector<int>(ALPHABET, 0)));
    for (int i = 1; i <= N; i++) {
      assert(T[i] != '?');
      sum[i][T[i] - 'a']++;
    }
    // 累積和にする
    for (int i = 1; i <= N; i++) {
      for (int c = 0; c < ALPHABET; c++) {
        sum[i][c] += sum[i - 1][c];
      }
    }
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        for (int c = 0; c < ALPHABET; c++) {
          count[i][j][c] = sum[j][c] - sum[i - 1][c];
        }
      }
    }

#if 0
    for (int i = 1; i <= N; i++) { print(i, sum[i]); };
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        print(i, j, count[i][j]);
      }
    }
#endif

    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        for (int c = 0; c < ALPHABET; c++) {
          int n = j - i + 1;
          if (count[i][j][c] > n / 2) {
            // [i, j]でcは過半数になっているので条件を満たさない
            return false;
          }
        }
      }
    }
    // OK
    //T.erase(T.begin());
    //cout << "OK: " << T << endl;
    return true;
  };
  auto dfs = [&](auto dfs, string T, int n = 0) -> void {
    if (n >= N) {
      // チェック
      if (check2(T)) {
        ans++;
      }
      return;
    }
    if (T[n] != '?') {
      dfs(dfs, T, n + 1);
      return;
    }
    for (int i = 0; i < ALPHABET; i++) {
      char c = 'a' + i;
      string now(T);
      now[n] = c;
      dfs(dfs, now, n + 1);
    }
  };
  dfs(dfs, S);
  cout << ans.val() << endl;
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  if (N == 2) {
    naive(N, S);
    return 0;
  }
  S = '_' + S;
  // dp[i][c][d] i=1..N, c, d=0, ... 25
  vector<vector<vector<mint> > > dp(N + 1, vector<vector<mint> >(ALPHABET, vector<mint>(ALPHABET, 0)));
  // 初期化 dp[3][c][d]
  for (int c = 0; c < ALPHABET; c++) {
    for (int d = 0; d < ALPHABET; d++) {
      if (S[3] != ('a' + c) && S[3] != '?') {
        continue;
      }
      if (S[2] != ('a' + d) && S[2] != '?') {
        continue;
      }
      if (!check(S[1], 'a' + c, 'a' + d)) {
        continue;
      }
      dp[3][c][d] = mint(S[1] == '?' ? (ALPHABET - 2) : 1);
    }
  }

  // 遷移 i - 1 --> i
  for (int i = 4; i <= N; i++) {
    for (int nc = 0; nc < ALPHABET; nc++) {
      for (int nd = 0; nd < ALPHABET; nd++) {
        int pc = nd;
        for (int pd = 0; pd < ALPHABET; pd++) {
          if (S[i] != ('a' + nc) && S[i] != '?') {
            continue;
          }
          if (!check_fast('a' + nc, 'a' + nd, 'a' + pd)) {
            continue;
          }
          dp[i][nc][nd] += dp[i - 1][pc][pd];
        }
      }
    }
  }
      
  mint ans = 0;
  for (int c = 0; c < ALPHABET; c++) {
    for (int d = 0; d < ALPHABET; d++) {
      ans += dp[N][c][d];
    }
  }
  cout << ans.val() << endl;
  return 0;
}
