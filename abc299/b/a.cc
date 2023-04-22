#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> C(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
  }
  vector<int> R(N);
  for (int n = 0; n < N; n++) {
    cin >> R.at(n);
  }
  // 1
  int ans = -1;
  int max = -1;
  for (int n = 0; n < N; n++) {
    if (C[n] == T) {
      if (R[n] > max) {
        max = R[n];
        ans = n;
      }
    }
  }
  if (ans >= 0) {
    ans++;
    cout << ans << endl;
    return 0;
  }
  // 2
  ans = -1;
  max = -1;
  for (int n = 0; n < N; n++) {
    if (C[n] == C[0]) {
      if (R[n] > max) {
        max = R[n];
        ans = n;
      }
    }
  }
  assert(ans >= 0);
  ans++;
  cout << ans << endl;
  return 0;
}
