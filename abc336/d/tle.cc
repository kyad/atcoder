#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int ans = 0;
  for (int left = 0; left < N; left++) {
    int kmax = (N - left + 1) / 2;
    for (int k = 0; k <= kmax; k++) {
      // kの時のチェック
      bool ok = true;
      for (int j = 0; j < k; j++) {
        if (A.at(left + j) < j + 1) {
          ok = false;
          break;
        }
      }
      for (int j = 0; j < k - 1; j++) {
        if (A.at(left + k + j) < k - 1 - j) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = max(ans, k);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
