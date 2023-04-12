#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P, Q;
  cin >> N >> P >> Q;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int ans = 0;

  // Next combination. Select r = 5 from N
  int r = 5;
  vector<bool> mask(N, true);
  fill(mask.begin(), mask.begin() + (N - r), false);  // 000..0011111
  do {
    // check
    long long now = 1;
    for (int i = 0; i < N; i++) {
      if (mask[i]) {
        // selected
        now *= A[i];
        now %= P;
      }
    }
    if (now == Q) {
      ans++;
    }
  } while (next_permutation(mask.begin(), mask.end()));

  cout << ans << endl;
  return 0;
}
