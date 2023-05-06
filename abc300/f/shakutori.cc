#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long shakutori(const string &T, long long K) {
  long long N = T.size();
  long long ans = 0;
  // 尺取り法。[left, right)は半開区間とする
  long long right = 0;
  long long sum = 0;  // [left, right)内のxの個数。K以下であること。
  for (long long left = 0; left < N; left++) {
    while (true) {
      long long nright = right + 1;
      if (nright >= N + 1) {
        break;
      }
      long long nsum = sum + (T[right] == 'x');
      if (nsum > K) {
        break;
      }
      right = nright;
      sum = nsum;
    }

    // この時点で[left, right)は条件を見たす最大の区間
    ans = max(ans, right - left);

    // leftをインクリメントする前の処理
    if (left == right) {
      // このとき、[left, right)は空集合なので、条件からleftを除外する処理は不要
      right++;  // 先にrightをインクリメントする
    } else {
      sum -= (T[left] == 'x');
    }
  }
  return ans;
}

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  string S;
  cin >> S;
  if (M == 1) {
    long long ans = shakutori(S, K);
    cout << ans << endl;
    return 0;
  }
  long long X = count(S.begin(), S.end(), 'x');
  long long C = K / X;  // C<=M
  C = min(C, M - 2);
  K -= C * X;
  long long ans = C * N + shakutori(S + S, K);
  cout << ans << endl;
  return 0;
}
