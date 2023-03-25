#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  long long ans = 0;
  for (int l = 0; l < N; l++) {
    for (int r = l; r < N; r++) {
      vector<int> count(10, 0);
      for (int k = l; k <= r; k++) {
        count[S[k] - '0']++;
      }
      bool ok = true;
      for (int d = 0; d <= 9; d++) {
        if (count[d] % 2 == 1) {
          ok = false;
        }
      }
      if (ok) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
