#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M, D;
  cin >> M >> D;
  string S;
  cin >> S;
  vector<bool> dp(M, false);
  for (int j = 0; j < M; j++) {
    if (S.at(j) == 'G') {
      int left = max(0, j - D);
      int right = min(M - 1, j + D);
      for (int k = left; k <= right; k++) {
        dp.at(k) = true;
      }
    }
  }
  int ans = count(dp.begin(), dp.end(), false);
  cout << ans << '\n';
  return 0;
}
