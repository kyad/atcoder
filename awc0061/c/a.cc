#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<long long> dp(N + 1, 0), mx(N + 1, 0);
  for (int i = 1; i <= K + 1; i++) {
    dp.at(i) = A.at(i);
    mx.at(i) = max(mx.at(i - 1), dp.at(i));
  }
  for (int i = K + 2; i <= N; i++) {
    dp.at(i) = mx.at(i - K - 1) + A.at(i);
    mx.at(i) = max(mx.at(i - 1), dp.at(i));
  }
  long long ans = *max_element(dp.begin(), dp.end());
  cout << ans << '\n';
  return 0;
}
