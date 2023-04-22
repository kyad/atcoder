#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  // Check all o
  bool ok = true;
  for (int n = 0; n < N; n++) {
    if (S[n] != 'o') {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << -1 << endl;
    return 0;
  }
  int ans = -1;
  int now = 0;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'o') {
      now++;
      ans = max(ans, now);
    } else {
      now = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
