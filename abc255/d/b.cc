// https://atcoder.jp/contests/abc255/tasks/abc255_d

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  vector<long long> sum(N + 1, 0);  // sum[i + 1] = A[0] + ... + A[i], sum[0] = 0
  for (int n = 1; n <= N; n++) {
    sum.at(n) += sum.at(n - 1) + A.at(n - 1);
  }
  const int INF = 1000000001;
  for (int q = 0; q < Q; q++) {
    long long X;
    cin >> X;
    if (X < A.at(0)) {
      long long ans = sum[N] - X * N;
      cout << ans << endl;
      continue;
    }
    // Find k such that A[k] <= X < A[k+1] (k = 0, 1, ..., N - 1)
    int left = 0;  // A[k] <= X
    A.push_back(INF);
    int right = N;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (A[mid] <= X) {
        left = mid;
      } else {
        right = mid;
      }
    }
    int k = left;
    long long ans = 0;
    ans += X * (k + 1) - sum[k + 1];
    ans += sum[N] - sum[k + 1] - X * (N - k - 1);
    cout << ans << endl;
  }
  return 0;
}
