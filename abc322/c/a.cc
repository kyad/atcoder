#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> ans(N + 1, -1);
  for (int m = 0; m < M; m++) {
    int A;
    cin >> A;
    ans[A] = 0;
  }
  for (int n = N - 1; n >= 1; n--) {
    if (ans[n] == 0) {
      continue;
    }
    ans[n] = ans[n + 1] + 1;
  }
  for (int n = 1; n <= N; n++) {
    cout << ans[n] << '\n';
  }
  return 0;
}
