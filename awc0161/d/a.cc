#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(2, 0)));
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < 2; k++) {
      dp.at(i).at(i).at(k) = A.at(i);
    }
  }
  for (int d = 1; d < N; d++) {
    for (int l = 0; l < N; l++) {
      int r = l + d;
      if (r >= N) {
        break;
      }
      dp.at(l).at(r).at(0) = min(dp.at(l + 1).at(r).at(1), dp.at(l).at(r - 1).at(1));
      dp.at(l).at(r).at(1) = max(dp.at(l + 1).at(r).at(0), dp.at(l).at(r - 1).at(0));
    }
  }
  long long ans = dp.at(0).at(N - 1).at(1);
  cout << ans << '\n';
  return 0;
}
