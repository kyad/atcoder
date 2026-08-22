#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  const long long INF = 4e18;
  long long ans = INF;
  for (int k = 0; k <= N - 2; k++) {
    long long left = 0;
    for (int i = 0; i <= k; i++) {
      left += L.at(i);
    }
    long long right = 0;
    for (int i = k + 1; i < N; i++) {
      right += L.at(i);
    }
    long long now = abs(left - right);
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
