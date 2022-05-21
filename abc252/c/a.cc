#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solve(int N, vector<string>& S, int d) {
  vector<bool> stopped(N, false);
  int t = 0;
  while (true) {
    bool ok = true;
    for (int n = 0; n < N; n++) {
      if (stopped[n] == false) {
        ok = false;
      }
    }
    if (ok) {
      break;
    }
    // Find
    for (int n = 0; n < N; n++) {
      if (stopped[n]) {
        continue;
      }
      if (S[n][t%10] == ('0' + d)) {
        stopped[n] = true;
        break;
      }
    }
    t++;
  }
  return t - 1;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  int ans = 100 * 100 * 10 + 1;
  for (int d = 0; d <= 9; d++) {
    int now = solve(N, S, d);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
