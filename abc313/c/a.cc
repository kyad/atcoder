#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long S = 0;
  for (int n = 0; n < N; n++) {
    S += A.at(n);
  }
  long long x = S / N;
  long long up = 0;
  long long down = 0;
  for (int n = 0; n < N; n++) {
    if (A[n] < x) {
      up += x - A[n];
    } else if (A[n] > x + 1) {
      down += A[n] - (x + 1);
    }
  }
  long long ans = max(up, down);
  cout << ans << endl;
  return 0;
}
