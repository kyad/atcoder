#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

int main() {
  int N;
  cin >> N;
  vector<long long> V(N);
  for (int i = 0; i < N; i++) {
    cin >> V.at(i);
  }
  vector<vector<long long>> dp(N, vector<long long>(N, -INF));
  for (int i = 0; i < N; i++) {
    dp.at(i).at(i) = V.at(i);
  }
  for (int d = 1; d <= N - 1; d++) {
    for (int i = 0; i < N - d; i++) {
      int j = i + d;
      long long left = V.at(i) - dp.at(i + 1).at(j);
      long long right = V.at(j) - dp.at(i).at(j - 1);
      dp.at(i).at(j) = max(left, right);
    }
  }
  long long ans = dp.at(0).at(N - 1);
  cout << ans << '\n';
  return 0;
}
