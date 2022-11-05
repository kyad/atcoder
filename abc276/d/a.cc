#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> p(N, 0), q(N, 0);
  for (int n = 0; n < N; n++) {
    while (A[n] % 2 == 0) {
      A[n] /= 2;
      p[n]++;
    }
    while (A[n] % 3 == 0) {
      A[n] /= 3;
      q[n]++;
    }
  }
  for (int n = 1; n < N; n++) {
    if (A[n] != A[0]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int minp = *min_element(p.begin(), p.end());
  int minq = *min_element(q.begin(), q.end());
  int sump = 0, sumq = 0;
  for (int n = 0; n < N; n++) {
    sump += p[n];
    sumq += q[n];
  }
  int ans = sump - minp * N + sumq - minq * N;
  cout << ans << endl;
  return 0;
}
