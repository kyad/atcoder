#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int y = 0; y < N; y++) {
    cin >> S.at(y);
  }
  const int INF = 1e9;
  // 1点更新・区間最小値
  vector<int> dp(N + 1, INF);
  for (int y = 0; y < N; y++) {
    vector<int> p(N + 1, INF);
    swap(p, dp);
    // この行で、iからを全部#にするための回数
    vector<int> c(N + 1, 0);
    c.at(0) = count(S.at(y).begin(), S.at(y).end(), '.');
    for (int i = 1; i <= N; i++) {
      if (S.at(y).at(i - 1) == '#') {
        c.at(i) = c.at(i - 1) + 1;
      } else {
        c.at(i) = c.at(i - 1) - 1;
      }
    }
    if (y == 0) {
      for (int i = 0; i <= N; i++) {
        dp.at(i) = c.at(i);
      }
    } else {
      int mn = INF;
      for (int i = N; i >= 0; i--) {
        mn = min(mn, p.at(i));
        dp.at(i) = c.at(i) + mn;
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= N; i++) {
    ans = min(ans, dp.at(i));
  }
  cout << ans << '\n';
  return 0;
}
