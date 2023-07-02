#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> B(N - 2), C(N - 2);
  for (int n = 0; n < N - 2; n++) {
    B.at(n) = A.at(n + 2);
    C.at(n) = -A.at(n + 2);
  }
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  const long long INF = 4e18;
  vector<long long> P(N - 1, INF);  // A[0]を左に動かしてj個増やすまでの最小手数 0<=j<=N-2
  vector<long long> Q(N - 1, INF);  // A[1]を右に動かしてj個増やすまでの最小手数 0<=j<=N-2
  {
    // P
    int k = lower_bound(C.begin(), C.end(), -A[0]) - C.begin();
    P[0] = 0;
    for (int i = k; i < N - 2; i++) {
      int j = i - k + 1;
      assert(0 <= j && j <= N - 2);
      P[j] = C[i] - (-A[0]);
    }
  }
  {
    // Q
    int k = lower_bound(B.begin(), B.end(), A[1]) - B.begin();
    Q[0] = 0;
    for (int i = k; i < N - 2; i++) {
      int j = i - k + 1;
      assert(0 <= j && j <= N - 2);
      Q[j] = B[i] - A[1];
    }
  }
  // S
  long long l = min(A[0], A[1]);
  long long r = max(A[0], A[1]);
  long long S = 0;
  for (int i = 2; i < N; i++) {
    if (l <= A[i] && A[i] <= r) {
      S++;
    }
  }
  if (A[1] < A[0]) {
    S *= -1;
  }
  //ans
  long long ans = INF;
  for (int i = 0; i <= N - 2; i++) {
    int j = M - S - i;
    if (j < 0 || j > N - 2) {
      continue;
    }
    long long now = P[i] + Q[j];
    ans = min(ans, now);
  }
  if (ans == INF) {
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}
