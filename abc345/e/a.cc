// https://www.youtube.com/watch?v=bgbxeo3oPH0&t=5948s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

struct D {
  long long value;  // 価値の総和
  int color;  // 色
};

struct Top2 {
  D a;  // 価値の総和1位
  D b;  // 価値の総和2位
  Top2() {
    a.value = -INF;
    a.color = -1;
    b.value = -INF;
    b.color = -2;
  }
  void chmax(long long value, int color) {
    // 2位と比較
    if (value > b.value) {
      swap(b.value, value);
      swap(b.color, color);
      // 1位と比較
      if (b.value > a.value) {
        swap(a.value, b.value);
        swap(a.color, b.color);
      }
      // 例外：1位と2位が同じ色の時は3位を採用する
      if (a.color == b.color) {
        b.value = value;
        b.color = color;
      }
    }
  };
  long long get(int color) {
    if (color == a.color) {
      return b.value;
    } else {
      return a.value;
    }
  };
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> C(N), V(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i] >> V[i];
  }
  // dp[i][j]: iまで見た時に、取り除いた個数がj(0<=j<=K)個の時の価値の総和の上位2個
  vector<Top2> dp(K + 1);
  // 初期値
  dp[0].a.value = 0;
  for (int i = 0; i < N; i++) {
    vector<Top2> prev(K + 1);
    swap(dp, prev);
    for (int j = 0; j <= K; j++) {  // 取り除いた個数
      // iを取り除く(iを取らない)
      if (j + 1 <= K) {
        dp[j + 1] = prev[j];
      }
      // iを取り除かない(iを取る)
      long long nvalue = prev[j].get(C[i]) + V[i];
      dp[j].chmax(nvalue, C[i]);
    }
  }
  long long ans = max(-1LL, dp[K].a.value);
  cout << ans << endl;
  return 0;
}
