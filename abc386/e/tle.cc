#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());  // Aは小さい順

  // next_combination(N, K)
  vector<int> mask(N, 1);
  for (int i = 0; i < N - K; i++) {  // 最初の方はmaskで出てくるのは大きい順
    mask.at(i) = 0;
  }
  long long ans = -1;
  int  count = 0;
  do {
    long long now = 0;
    if (count * N > 2e9) {
      break;
    }
    for (int i = 0; i < N; i++) {
      if (mask.at(i)) {  
        // Do something
        now ^= A.at(i);
      }
    }
    ans = max(ans, now);
    count++;
  } while (next_permutation(mask.begin(), mask.end()));

  cout << ans << endl;
  return 0;
}
