#include <algorithm>
#include <cassert>
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
  sort(A.begin(), A.end());
  vector<long long> R(N); // A[i] + ... + A[N - 1]
  R.at(N - 1) = A.at(N - 1);
  for (int i = N - 2; i >= 0; i--) {
    R.at(i) = R.at(i + 1) + A.at(i);
  }
  long long ans = 0;
  long long E = 100000000;
  for (int i = 0; i < N - 1; i++) {
    int c = A.end() - lower_bound(A.begin(), A.end(), E - A.at(i));
    c = min(c, N - 1 - i);
    long long now = (long long)(N - i - 1) * A.at(i) + R.at(i + 1) - (long long)c * E;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
