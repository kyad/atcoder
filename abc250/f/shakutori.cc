// https://atcoder.jp/contests/abc250/tasks/abc250_f

#include <iostream>
#include <vector>
using namespace std;

template<class T> T outprod2(T ax, T ay, T bx, T by) {
  return ax * by - ay * bx;
}

// 面積の8倍を返す
long long area(long long x0, long long y0, long long x1, long long y1, long long x2, long long y2) {
  long long ax = x1 - x0;
  long long ay = y1 - y0;
  long long bx = x2 - x0;
  long long by = y2 - y0;
  long long ans = abs(outprod2(ax, ay, bx, by)) * 4LL;
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  long long T = 0;  // 凸N角形の面積
  auto S = [&](int i, int j, int k) {
    i %= N; j %= N; k %= N;
    return area(X[i], Y[i], X[j], Y[j], X[k], Y[k]);
  };
  for (int n = 1; n < N - 1; n++) {
    T += S(0, n, n + 1);
  }
  long long ans = T + 1;  // INF
  long long A = T / 4;

  long long sum = 0;
  int right = 0;
  for (int left = 0; left < N; left++) {
    while (sum + S(left, right, right + 1) < A) {
      sum += S(left, right, right + 1);
      ans = min(ans, abs(sum - A));
      right++;
    }
    // 1つ先もチェック
    ans = min(ans, abs(sum + S(left, right, right + 1) - A));

    sum -= S(left, left + 1, right);
    if (right == left) {
      right++;
      // この場合はsum == 0のはずなので、sumから引かなくても良い
    }
  }
  cout << ans << endl;
  return 0;
}
