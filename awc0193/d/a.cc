#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N;
  cin >> N;
  const long long INF = 4e18;
  vector<vector<long long>> dp(N + 1, vector<long long>(2, -INF));
  dp.at(0).at(0) = 0;
  for (int i = 1; i <= N; i++) {
    long long A, B;
    cin >> A >> B;
    chmax(dp.at(i).at(0), dp.at(i - 1).at(0) + A);
    chmax(dp.at(i).at(0), dp.at(i - 1).at(1) + A);
    chmax(dp.at(i).at(1), dp.at(i - 1).at(0) + B);
  }
  long long ans = max(dp.at(N).at(0), dp.at(N).at(1));
  cout << ans << '\n';
  return 0;
}
