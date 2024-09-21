#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

// m^n, O(log n)
long long power(long long m, long long n, int mod) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int M;
  cin >> M;
  vector<int> B(11, 0);  // B[a] = 3^a
  for (int a = 0; a <= 10; a++) {
    B.at(a) = power(3, a, 100000000);
  }
  vector<int> A;
  while (M > 0) {
    for (int a = 10; a >= 0; a--) {
      int b = B.at(a);
      if (M >= b) {
        A.push_back(a);
        M -= b;
        break;
      }
    }
  }
  int N = A.size();
  assert(N <= 20);
  cout << N << endl;
  dump(A);
  return 0;
}
