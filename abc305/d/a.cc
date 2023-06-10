#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int _N;
  cin >> _N;
  int M = (_N - 1) / 2;
  vector<long long> A(M + 1, -1);
  vector<long long> B(M, -1);
  for (int m = 0; m < M; m++) {
    cin >> A.at(m) >> B.at(m);
  }
  cin >> A.at(M);
  vector<long long> S(M + 1, 0);
  for (int m = 1; m < M; m++) {
    S.at(m) = A.at(m) - B.at(m - 1);
  }
  vector<long long> T(M + 1, 0);
  for (int m = 1; m < M; m++) {
    T.at(m) = T.at(m - 1) + S.at(m);
  }

  auto f = [&](long long x) -> long long {
    int p = lower_bound(A.begin(), A.end(), x) - A.begin();
    if (p == 0) {
      return 0;
    }
    long long ans = T[p - 1];
    if (x <= B.at(p - 1)) {
    } else {
      long long now = x - B.at(p - 1);
      ans += now;
    }
    return ans;
  };

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    long long l, r;
    cin >> l >> r;
    long long now1 = f(l);
    long long now2 = f(r);
    long long ans = now2 - now1;
    cout << ans << '\n';
  }
  return 0;
}
