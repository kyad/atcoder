#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  for (int m = 0; m < M; m++) {
    cin >> X.at(m);
    X.at(m)--;
  }
  // S[i]: 橋iを封鎖すると増える数
  vector<long long> S(N * 2 + 1, 0);
  long long ans = 0;
  for (int m = 0; m < M - 1; m++) {
    int a = abs(X.at(m + 1) - X.at(m));
    int b = N - a;
    int mx = max(a, b);
    int mn = min(a, b);
    int diff = mx - mn;
    int l, r;
    if ((X.at(m) + mn) % N == X.at(m + 1)) {
      // 増える方向に進むべき時
      l = X.at(m);
      r = X.at(m) + mn;
    } else {
      // 減る方向に進むべき時
      l = X.at(m + 1);
      r = X.at(m + 1) + mn;
    }
    assert(r <= 2 * N);
    S.at(l) += (long long)diff;
    S.at(r) -= (long long)diff;
    ans += (long long) mn;
  }
  // imos
  for (int i = 0; i < 2 * N; i++) {
    S.at(i + 1) += S.at(i);
  }
  // ループの処理
  vector<long long> T(N, 0);
  for (int i = 0; i < N; i++) {
    T.at(i) = S.at(i) + S.at(i + N);
  }
  const long long INF = 4e18;
  long long mn = INF;
  for (int i = 0; i < N; i++) {
    mn = min(mn, T.at(i));
  }
  ans += mn;
  cout << ans << endl;
  return 0;
}
