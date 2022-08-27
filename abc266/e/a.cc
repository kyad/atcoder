#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> dp(N + 1, 0);
  dp[1] = 21. / 6;
  for (int i = 2; i <= N; i++) {
    double sum = 0;
    for (int j = 1; j <= 6; j++) {
      if (j < dp[i - 1]) {
        sum += dp[i - 1];
      } else {
        sum += j;
      }
    }
    dp[i] = sum / 6;
  }
  cout << setprecision(15) << dp[N] << endl;
  return 0;
}
