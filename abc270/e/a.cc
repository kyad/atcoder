#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (long long n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  auto f = [&](long long X) -> long long {
    long long ans = 0;
    for (long long n = 0; n < N; n++) {
      ans += min(X, A.at(n));
    }
    return ans;
  };
  long long left = 0;  // OK
  long long right = K + 1;  // NG
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (f(mid) <= K) {  // OK
      left = mid;
    } else {
      right = mid;
    }
  }
  long long sum = f(left);
  K -= sum;
  for (long long n = 0; n < N; n++) {
    A.at(n) = max(0LL, A.at(n) - left);
  }
  for (long long n = 0; n < N; n++) {
    if (K > 0) {
      if (A.at(n) > 0) {
        A.at(n)--;
        K--;
      }
    }
  }
  for (long long n = 0; n < N; n++) {
    cout << A.at(n) << ' ';
  }
  cout << endl;
  return 0;
}
