// https://atcoder.jp/contests/abc229/tasks/abc229_d

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int K;
  cin >> K;
  int N = (int)S.size();
  vector<int> sum(N + 1, 0);  // 1-indexed
  for (int n = 1; n <= N; n++) {
    if (S[n - 1] == '.') {
      sum[n] = sum[n - 1] + 1;
    } else {
      sum[n] = sum[n - 1];
    }
  }
  int ans = 0;
  // [left, right)
  int right = 0;
  for (int left = 0; left < N; left++) {
    while ((right <= N - 1) && (sum[right + 1] - sum[left] <= K)) {
      right++;
    }
    int len = right - left;
    ans = max(ans, len);
  }
  cout << ans << endl;
  return 0;
}
