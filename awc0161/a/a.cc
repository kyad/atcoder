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
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  // 順列初期化
  vector<int> P(N, -1);
  for (int i = 0; i < N; i++) {
    P.at(i) = i;
  }
  // 順列全探索
  int ans = -1;
  do {
    int now = 0;
    for (int i = 0; i < N - 1; i++) {
      int p = P.at(i);
      int q = P.at(i + 1);
      now += abs(A.at(q) - A.at(p));
    }
    ans = max(ans, now);
  } while (next_permutation(P.begin(), P.end()));
  cout << ans << '\n';
  return 0;
}
