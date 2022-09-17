// https://atcoder.jp/contests/abc268/tasks/abc268_e

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  // 時刻iにおける不満度v = ix[i] * x + iv[i]
  vector<long long> ix(2 * N, 0);
  vector<long long> iv(2 * N, 0);
  for (int i = 0; i < N; i++) {  // 人iに対するループ
    // 不満度が0になる回数
    int j = (P[i] - i + N) % N;
    // v = x - j  (j<=x<=j+N//2)
    ix[j] += 1;
    ix[j + N / 2 + 1] -= 1;
    iv[j] += (-j);
    iv[j + N / 2 + 1] -= (-j);
    // v = -x + (N + j)  (N + j - N//2<=x<=N+j)
    ix[N + j - (N - 1) / 2] += (-1);
    ix[N + j + 1] -= (-1);
    iv[N + j - (N - 1) / 2] += (N + j);
    iv[N + j + 1] -= (N + j);
  }
  for (int i = 1; i < 2 * N; i++) {
    ix[i] += ix[i - 1];
    iv[i] += iv[i - 1];
  }
  long long ans = 4e18;
  for (int i = 0; i < N; i++) {  // 時刻iに対するループ
    long long v = ix[i] * i + iv[i];
    v += (ix[N + i] * (N + i) + iv[N + i]);
    ans = min(ans, v);
  }
  cout << ans << endl;
  return 0;
}
