#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> V(N + 1, 0), C(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> V.at(i) >> C.at(i);
  }
  int M = 10000;
  const int INF = 1e9;
  vector<vector<int> > dp(N + 1, vector<int>(M + 1, -INF));
  dp.at(0).at(0) = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      chmax(dp.at(i).at(j), dp.at(i - 1).at(j));  // 買わない
      if (j - C.at(i) >= 0) {
        chmax(dp.at(i).at(j), dp.at(i - 1).at(j - C.at(i)) + V.at(i));  // 買う
      }
    }
  }
  int ans = dp.at(N).at(S);
  if (ans < 0) {
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
