#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<int> dp(2 * N + 1, -1);
  dp[1] = 0;
  for (int i = 1; i <= N; i++) {
    dp[2 * i] = dp[A[i]] + 1;
    dp[2 * i + 1] = dp[A[i]] + 1;
  }
  for (int i = 1; i <= 2 * N + 1; i++) {
    cout << dp[i] << '\n';
  }
  return 0;
}
