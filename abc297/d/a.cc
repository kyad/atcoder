#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  long long A, B;
  cin >> A >> B;
  long long ans = 0;
  while (true) {
    if (A == B) {
      break;
    }
    if (B < A) {
      swap(A, B);
    }
    assert(A < B);
    assert(A > 0);
    long long now = ceildiv(B - A, A);
    ans += now;
    B = B - A * now;
  }
  cout << ans << endl;
  return 0;
}
