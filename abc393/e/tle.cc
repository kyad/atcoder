// https://www.youtube.com/live/RLCWqyDaZU4?t=4876s
// TLE: O(N*sqrt(M))解法

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  const int M = 1e6;
  vector<int> num(M + 1, 0);
  for (int i = 0; i < N; i++) {
    num.at(A.at(i))++;
  }
  // c[j]: Aの要素のうちjの倍数の個数
  vector<int> c(M + 1, 0);
  for (int j = 1; j <= M; j++) {
    for (int k = j; k <= M; k += j) {
      c.at(j) += num.at(k);
    }
  }

  for (int i = 0; i < N; i++) {
    int ans = -1;
    // A[i]の約数を列挙
    for (int j = 1; j * j <= A.at(i); j++) {
      if (A.at(i) % j != 0) {
        continue;
      }
      // jはA[i]の約数
      if (c.at(j) >= K) {
        ans = max(ans, j);
      }
      // A[i]/jはA[i]の約数
      if (c.at(A[i]/j) >= K) {
        ans = max(ans, A[i]/j);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}