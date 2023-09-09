#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

long long lcm(long long a, long long b) {
  return a / __gcd(a, b) * b;
}

int main() {
  int N;
  long long X, Y;
  cin >> N >> X >> Y;
  vector<long long> P(N);
  vector<long long> T(N);
  long long L = 1;
  for (int n = 0; n < N - 1; n++) {
    cin >> P.at(n) >> T.at(n);
    L = lcm(L, P.at(n));
  }

  auto sim = [&](long long A) -> long long {
    long long t = A;
    t += X;
    for (int n = 0; n < N - 1; n++) {
      // 待つ
      t = ceildiv(t, P[n]) * P[n];
      // バス
      t += T[n];
    }
    t += Y;
    return t;
  };

  vector<long long> diffs(L);
  for (long long a = 0; a < L; a++) {
    long long ans = sim(a);
    long long diff = ans - a;
    diffs[a] = diff;
  }

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    long long A;
    cin >> A;
    //long long ans = sim(A);
    long long diff = diffs[A % L];
    long long ans = diff + A;
    cout << ans << endl;
  }

  return 0;
}
