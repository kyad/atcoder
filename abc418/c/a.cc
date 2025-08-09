#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<long long> C(A);
  sort(C.begin(), C.end());
  vector<long long> S(N, 0);
  S.at(0) = C.at(0);
  for (int i = 1; i < N; i++) {
    S.at(i) = S.at(i - 1) + C.at(i);
  }
  long long sum = S.at(N - 1);
  const int M = 1000000;
  //const int M = 11;
  vector<long long> dp(M + 1, 0);
  for (int y = 0; y <= M; y++) {
    int i = lower_bound(C.begin(), C.end(), y) - C.begin();
    if (i >= 1) {
      dp.at(y) += S.at(i - 1);
    }
    dp.at(y) += (long long)y * (N - i);
    dp.at(y)++;
    if (dp.at(y) >= sum + 1) {
      dp.at(y) = -1;
    }
    //cerr << y << ' ' << dp.at(y) << endl;
  }
  for (int qi = 0; qi < Q; qi++) {
    int b;
    cin >> b;
    long long ans = dp.at(b - 1);
    cout << ans << '\n';
  }
  return 0;
}
