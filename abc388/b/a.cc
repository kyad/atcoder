#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> T(N), L(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i) >> L.at(i);
  }
  for (int k = 1; k <= D; k++) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
      int now = T.at(i) * (L.at(i) + k);
      ans = max(ans, now);
    }
    cout << ans << '\n';
  }
  return 0;
}
