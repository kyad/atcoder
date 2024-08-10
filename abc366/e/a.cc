#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long D;
  cin >> N >> D;
  vector<long long> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }

  long long Xmin;
  {
    long long d0 = 0;
    for (int i = 0; i < N; i++) {
      d0 += X.at(i);
    }
    Xmin = (d0 - D) / N - 1;
  }

  long long Xmax;
  {
    long long d1 = 0;
    for (int i = 0; i < N; i++) {
      d1 += X.at(i);
    }
    Xmax = (d1 + D) / N + 1 + 1;
  }

  long long Ymin = *min_element(Y.begin(), Y.end()) - D;
  long long Ymax = *max_element(Y.begin(), Y.end()) + D;

  vector<long long> YY(Y);
  sort(YY.begin(), YY.end());
  long long M = YY.at(N / 2);
  auto f = [&](long long y) -> long long {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      ans += abs(y - Y.at(i));
    }
    return ans;
  };

  long long ans = 0;
  for (long long x = Xmin; x <= Xmax; x++) {
    long long R = D;
    for (int i = 0; i < N; i++) {
      R -= abs(x - X.at(i));
    }
    if (R < 0) {
      continue;
    }
    // Yの和をR以下にしたい。
    if (f(M) > R) {
      continue;  // 最小値でもダメならダメ
    }
    long long now = 1;  // Mの分
    // 上方向
    {
      long long left = M;  // OK
      long long right = Ymax + 1;  // NG
      while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (f(mid) <= R) {  // OK
          left = mid;
        } else {
          right = mid;
        }
      }
      long long up = left - M;  // 上方向の個数(Mを除く)
      assert(up >= 0);
      now += up;
    }
    // 下方向
    {
      long long left = Ymin - 1;  // NG
      long long right = M;  // OK
      while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (f(mid) <= R) {  // OK
          right = mid;
        } else {
          left = mid;
        }
      }
      long long down = M - right;  // 上方向の個数(Mを除く)
      assert(down >= 0);
      now += down;
    }
    ans += now;
  }

  cout << ans << endl;
  return 0;
}
