#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long D;
  cin >> N >> M >> D;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<long long> C(M);
  for (int m = 0; m < M; m++) {
    C[m] = -B[m];
  }
  sort(C.begin(), C.end());
  long long ans = -1;
  for (int i = 0; i < N; i++) {
    vector<long long>::iterator l = lower_bound(B.begin(), B.end(), A[i] - D);
    vector<long long>::iterator r = lower_bound(C.begin(), C.end(), -(A[i] + D));
    if (l == B.end()) {
      continue;
    }
    if (r == C.end()) {
      continue;
    }
    if (*l > -(*r)) {
      continue;
    }
    long long now = max(*l + A[i], -(*r) + A[i]);
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
