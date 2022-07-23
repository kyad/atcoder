#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, C;
  cin >> N >> C;
  vector<int> dp(2, 0);
  for (int i = 0; i <= 30; i++) {
    dp[1] |= (1<<i);
  }
  for (int n = 0; n < N; n++) {
    int T, A;
    cin >> T >> A;
    if (T == 1) {
      dp[0] &= A;
      dp[1] &= A;
    } else if (T == 2) {
      dp[0] |= A;
      dp[1] |= A;
    } else {
      dp[0] ^= A;
      dp[1] ^= A;
    }
    int ans = 0;
    for (int i = 0; i <= 30; i++) {
      if ((C>>i)&1) {
        ans |= (dp[1] & (1<<i));
      } else {
        ans |= (dp[0] & (1<<i));
      }
    }
    cout << ans << endl;
    C = ans;
  }
  return 0;
}
