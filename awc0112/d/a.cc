#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> V(N + 1, 0);
  vector<int> W(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> V.at(i) >> W.at(i);
  }
  const long long INF = 4e18;
  vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(K + 1, vector<long long>(2, -INF)));
  dp.at(0).at(0).at(0) = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      chmax(dp.at(i).at(j).at(0), dp.at(i - 1).at(j).at(0));
      chmax(dp.at(i).at(j).at(0), dp.at(i - 1).at(j).at(1));
      if (j - W.at(i) >= 0) {
        chmax(dp.at(i).at(j).at(1),
              dp.at(i - 1).at(j - W.at(i)).at(0) + V.at(i));
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= K; j++) {
    for(int k = 0; k <= 1; k++){
      chmax(ans, dp.at(N).at(j).at(k));
    }
  }
  cout << ans << '\n';
  return 0;
}
