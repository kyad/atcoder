#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> count(N + 1, 0);
  // Sieve of Eratosthenes
  // Time Complexity: O(N*loglog(N)) (N=10^7 is OK)
  for (int n = 2; n <= N; n++) {
    if (count[n] > 0) {  // 素数でない
      continue;
    }
    // 素数
    for (int m = n; m <= N; m += n) {
      count[m]++;
    }
  }
  int ans = 0;
  for (int n = 2; n <= N; n++) {
    if (count[n] >= K) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
