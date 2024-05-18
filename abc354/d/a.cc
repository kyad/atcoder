#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long M = 1000000000;

long long f(long long A, long long B) {
  long long p = A / 4;
  long long q = B / 2;
  long long T = p * q * 8;
  if (A % 4 == 1) {
    T += 3 * q;
  } else if (A % 4 == 2) {
    T += 3 * q;
    T += 3 * q;
  } else if (A % 4 == 3) {
    T += 3 * q;
    T += 3 * q;
    T += q;
  }

  if (B == q * 2 + 1) {
    T += p * 4;
    if (A % 4 == 1) {
      T += 2;
    } else if (A % 4 == 2) {
      T += 2;
      T += 1;
    } else if (A % 4 == 3) {
      T += 2;
      T += 1;
    }
  }
  return T;
}

int main() {
  long long A, B, C, D;
  cin >> A >> B >> C >> D;
  A += (M + 4LL);
  B += M;
  C += (M + 4LL);
  D += M;
  long long ans = f(A, B) - f(A, D) - f(C, B) + f(C, D);
  cout << ans << endl;
  return 0;
}
