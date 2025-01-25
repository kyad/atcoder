#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す
template<class T> T ceildiv(T a, T b);
// floor(a / b)を計算する。aが負の場合は負の無限大へ丸める。
template<class T> T floordiv(T a, T b) { assert(b > 0); return (a >= 0) ? (a / b) : (-ceildiv(-a, b)); }
// ceil(a / b)を計算する。aが負の場合は正の無限大へ丸める。
template<class T> T ceildiv(T a, T b) { assert(b > 0); return (a >= 0) ? ((a + b - 1) / b) : (-floordiv(-a, b)); }

const int INF = 1e9;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> M(3);  // M[v]: ビタミンvの個数
  vector<vector<int> > B(3);  // B[v][i]: ビタミンvの食べ物のビタミン量
  vector<vector<int> > D(3);  // D[v][i]: ビタミンvの食べ物のカロリー
  int sumA = 0;
  for (int i = 0; i < N; i++) {
    int V, A, C;
    cin >> V >> A >> C;
    V--;
    M.at(V)++;
    B.at(V).push_back(A);
    D.at(V).push_back(C);
    sumA += A;
  }
  for (int v = 0; v < 3; v++) {
    assert((int)B.at(v).size() == M.at(v));
    assert((int)D.at(v).size() == M.at(v));
  }

  vector<vector<vector<int> > > dp(3, vector<vector<int> > (X + 1));
  for (int v = 0; v < 3; v++) {
    for (int j = 0; j <= X; j++) {
      dp.at(v).at(j) = vector<int>(M.at(v) + 1, -INF);
    }
  }
  // 全ビタミンをK以上摂取でき、かつ、カロリーの合計をX以下にできるか？
  auto check = [&](int K) -> bool {
    int sum = 0;
    for (int v = 0; v < 3; v++) {
      int m = M.at(v);
      int now = INF;
      // dp[j][i]: iまで見た時にカロリーjとなるときのビタミンの最大値
      //vector<vector<int> > dp(X + 1, vector<int>(m + 1, -INF));
      // DPをクリア、初期化
      for (int j = 0; j <= X; j++) {
        for (int i = 1; i <= m; i++) {
          dp[v][j][i] = -INF;
        }
      }
      dp[v][0][0] = 0;

      for (int j = 0; j <= X; j++) {
        for (int i = 1; i <= m; i++) {
          chmax(dp[v][j][i], dp[v][j][i - 1]);  // 取らない
          if (j - D.at(v).at(i - 1) >= 0) {  // 取る
            chmax(dp[v][j][i], dp[v][j - D.at(v).at(i - 1)][i - 1] + B.at(v).at(i - 1));
          }
          if (dp[v][j][i] >= K) {  // ビタミンvをK以上摂取できた
            now = j;  // 最小カロリー
            break;
          }
        }
        if (now != INF) {
          break;
        }
      }
      // ビタミンをK以上にできない時
      if (now == -1) {
        return false;
      }
      sum += now;
      if (sum > X) {  // 枝刈り
        return false;
      }
    }
    // カロリーがXより大きい時
    if (sum > X) {
      return false;
    } else {
      return true;
    }
  };

  int left = 0;  // OK
  int right = ceildiv(sumA, 3) + 1;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  int ans = left;
  cout << ans << endl;
  return 0;
}
