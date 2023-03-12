#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long f(long long x) {
  long long ans = 0;
  while (x > 0) {
    long long now = x % 10;
    ans += now;
    x /= 10;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += f(A[i] + A[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
