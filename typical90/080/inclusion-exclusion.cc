#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> B(N);
  for (int n = 0; n < N; n++) {
    B.at(n) = ~A.at(n);
  }
  const long long N2 = 1LL<<N;
  const long long D2 = 1LL<<D;
  long long sum = 0;
  for (int bit = 1; bit < N2; bit++) {
    long long sgn = __builtin_popcountll(bit) % 2 == 1 ? +1 : -1;
    long long a = 0;
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {
        a |= A[i];
      }
    }
    const long long na = (~a) & (D2 - 1);
    const int n1 = __builtin_popcountll(na);
    long long now = 1LL<< (n1);
    now *= sgn;
    sum += now;
  }
  long long all = D2;
  long long ans = all - sum;
  cout << ans << endl;
  return 0;
}
