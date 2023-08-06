#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  int mx = 0;
  for (int n = 1; n < N; n++) {
    mx = max(mx, P[n]);
  }
  int ans;
  if (P[0] > mx) {
    ans = 0;
  } else {
    ans = mx - P[0] + 1;
  }
  cout << ans << endl;
  return 0;
}
