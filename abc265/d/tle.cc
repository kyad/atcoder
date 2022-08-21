#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long P, Q, R;
  cin >> N >> P >> Q >> R;
  vector<long long> A(N, 0); // 1-indexed
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  bool ans = false;
  for (int x = 0; x <= N; x++) {
    for (int y = x + 1; y <= N; y++) {
      long long sum0 = 0;
      for (int k = x; k <= y - 1; k++) {
        sum0 += A[k];
      }
      if (sum0 != P) {
        continue;
      }
      for (int z = y + 1; z <= N; z++) {
        long long sum = 0;
        for (int k = y; k <= z - 1; k++) {
          sum += A[k];
        }
        if (sum != Q) {
          continue;
        }
        for (int w = z + 1; w <= N; w++) {
          long long sum = 0;
          for (int k = z; k <= w - 1; k++) {
            sum += A[k];
          }
          if (sum != R) {
            continue;
          }
          ans = true;
          break;
        }
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
