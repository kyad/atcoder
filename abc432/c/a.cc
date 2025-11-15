#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long X, Y;
  cin >> N >> X >> Y;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  vector<long long> x(N, 0);
  // x[0]=0
  long long k = Y * A[0];
  long long ans = A[0];
  for (int i = 1; i < N; i++) {
    long long P = Y - X;
    long long Q = Y * A[i] - k;
    if (Q % P != 0) {
      cout << -1 << endl;
      return 0;
    }
    x[i] = Q / P;
    if (0 <= x[i] && x[i] <= A[i]) {
    } else {
      cout << -1 << endl;
      return 0;
    }
    long long now = A[i] - x[i];
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
