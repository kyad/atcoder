#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
   cin >> A.at(n);
  }

  vector<vector<long long> > xs(N + 1);
  vector<int> prev(N + 1, -1);
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    if (prev.at(a) >= 0) {
      long long now = i - prev.at(a) - 1;
      xs.at(a).push_back(now);
    }
    prev.at(a) = i;
  }

  auto solve = [&](int y) {
    // ランレングス
    int M = xs.at(y).size();
    // 計算
    long long ans = 0;
    for (int m = 0; m < M; m++) {
      ans += (long long)(M - m) * (long long)(m + 1) * (long long)xs.at(y).at(m);
    }
    return ans;
  };
  long long ans = 0;
  for (int y = 1; y <= N; y++) {
    ans += solve(y);
  }
  cout << ans << endl;
  return 0;
}
