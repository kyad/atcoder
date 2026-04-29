#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P, T, C;
  cin >> N >> P >> T >> C;
  vector<int> S(N, 0);
  for (int i = 1; i < N; i++) {
    cin >> S.at(i);
  }
  if (P >= T) {
    cout << 0 << endl;
    return 0;
  }
  const int INF = 2e9;
  int ans = INF;
  for (int i = 1; i < N; i++) {
    if (S.at(i) >= T) {
      ans = min(ans, C);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
