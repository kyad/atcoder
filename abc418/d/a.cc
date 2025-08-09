#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  vector<vector<long long> > dp(N + 1, vector<long long>(2, 0));
  for (int i = 1; i <= N; i++) {
    // i-1まで取らない、iのみ取る
    int k = S.at(i) - '0';
    dp.at(i).at(k) += 1;
    // i-1まで取る、iも取る
    if (S.at(i) == '0') {
      dp.at(i).at(0) += dp.at(i - 1).at(1);
      dp.at(i).at(1) += dp.at(i - 1).at(0);
    } else {
      dp.at(i).at(0) += dp.at(i - 1).at(0);
      dp.at(i).at(1) += dp.at(i - 1).at(1);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += dp.at(i).at(1);
  }
  cout << ans << endl;
  return 0;
}
