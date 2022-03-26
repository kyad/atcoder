#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N + 1, 0), B(M + 1, 0), C(N + M + 1, 0);
  for (int n = 0; n <= N; n++) {
    cin >> A.at(n);
  }
  for (int k = 0; k <= N + M; k++) {
    cin >> C.at(k);
  }
  for (int k = M; k >= 0; k--) {
    int sum = 0;
    for (int l = k + 1; l <= M; l++) {
      int x = N + k - l;
      if (x < 0) {
        continue;
      }
      sum += A[x] * B[l];
    }
    B[k] = (C[N + k] - sum) / A[N];
  }
  for (int m = 0; m <= M; m++) {
    cout << B[m];
    if (m == M) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}
