#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<long long> C(A);
  for (int i = 1; i < N; i++) {
    C.at(i) += C.at(i - 1);
  }
  vector<long long> S(N, 0);
  S.at(0) = C.at(0);
  for (int k = 1; k < N; k++) {
    S.at(k) = S.at(k - 1) + C.at(k);
  }
  vector<long long> is;
  long long idx = 0;
  for (int i = 0; i <= N; i++) {
    is.push_back(idx);
    idx += (long long)(i + 2);
  }
  auto f = [&](long long R) -> long long {
    if (R < 0) {
      return 0;
    }
    int k = prev(upper_bound(is.begin(), is.end(), R)) - is.begin();
    long long P = S.at(k);
    long long Q = 0;
    if (R - is.at(k) - 1 >= 0) {
      Q = C.at(R - is.at(k) - 1);
    }
    long long ans = P + Q;
    return ans;
  };
  for (int q = 0; q < Q; q++) {
    long long L, R;
    cin >> L >> R;
    L--;
    R--;
    long long ans = f(R) - f(L - 1);
    cout << ans << '\n';
  }
  return 0;
}
