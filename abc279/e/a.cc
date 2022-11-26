#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M + 1, 0);
  for (int m = 1; m <= M; m++) {
    cin >> A.at(m);
  }
  int now = 1;
  vector<int> L(M + 1, 0);
  for (int i = 1; i <= M; i++) {
    assert(now >= 1);
    assert(now <= N);
    L[i] = now;
    if (A[i] == now) {
      now++;
    } else if (A[i] + 1 == now) {
      now--;
    }
  }
  vector<int> R(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    R.at(n) = n;
  }
  vector<int> S(M + 1, 0);
  for (int i = M; i >= 1; i--) {
    S[i] = R[L[i]];
    assert(A[i] >= 1);
    assert(A[i] + 1 <= N);
    swap(R[A[i]], R[A[i] + 1]);
  }
  for (int i = 1; i <= M; i++) {
    cout << S[i] << '\n';
  }
  return 0;
}
