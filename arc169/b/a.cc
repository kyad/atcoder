#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long S;
  cin >> N >> S;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }

  // K[i]: i番目から見た時に和が初めてSを越えるindex(半開区間とする)。最大N
  vector<int> K(N, -1);
  // 尺取り法。[left, right)は半開区間とする
  int right = 0;
  long long sum = 0;
  for (int left = 0; left < N; left++) {
    // 条件を満たす最大のrightを求める
    while (true) {
      int nright = right + 1;
      if (nright >= N + 1) {
        break;
      }
      // nrightが条件を満たしているかチェック
      // 例：
      // int nsum = sum + (T[right] == 'x');
      // if (nsum > K) {
      //   break;
      // }
      long long nsum = sum + A[right];
      if (nsum > S) {
        break;
      }
      right = nright;
      // 条件にrightを含める
      // 例：
      // sum = nsum;
      sum = nsum;
    }

    // この時点で[left, right)は条件を見たす最大の区間
    // 何かする。
    // 例：
    // ans = max(ans, right - left);
    K[left] = right;
    assert(0 < K[left] && K[left] <= N);

    // leftをインクリメントする前の処理
    if (left == right) {
      // このとき、[left, right)は空集合なので、条件からleftを除外する処理は不要
      right++;  // 先にrightをインクリメントする
    } else {
      // 条件からleftを除外する
      // 例：
      // sum -= (T[left] == 'x');
      sum -= A[left];
    }
  }

  // lから初めた時の和
  vector<long long> memo(N + 1, -1);
  memo[N] = 0;
  auto T = [&](auto T, int l) -> long long {
    if (memo[l] >= 0) {
      return memo[l];
    }
    assert(0 <= l && l < N);
    int k = K[l];
    long long ans = T(T, k) + (long long)(N - l);
    return memo[l] = ans;
  };

  long long ans = 0;
  for (int l = 0; l < N; l++) {
    long long now = T(T, l);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
