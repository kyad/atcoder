#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using lll = __int128;

int main() {
  int N, M;
  long long W;
  cin >> N >> W >> M;
  vector<long long> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i) >> R.at(i);
    L.at(i)--;
    R.at(i)--;
  }

  const int D = 7;
  vector<long long> P(D, W);  // P[l]: l曜日に来場した時のポイント
  auto f = [&](long long E, long long x) {
    if (E < 0) {
      return;
    }
    for (long long l = 0; l < D; l++) {
      P.at(l) += (E / D) * x;
    }
    for (long long d = E / D * D; d <= E; d++) {
      P.at(d % D) += x;
    }
  };
  for (int j = 0; j < M; j++) {
    long long S, E;
    cin >> S >> E;
    S--; E--;
    f(E, +1);
    f(S - 1, -1);
  }
  for (int i = 0; i < N; i++) {
    long long ans = 0;
    auto g = [&](long long d0, long long d1) {
      for (long long d = d0; d <= d1; d++) {
        ans += P.at(d);
      }
    };
    if (L.at(i) <= R.at(i)) {
      g(L.at(i), R.at(i));
    } else {
      g(0, R.at(i));
      g(L.at(i), 6);
    }
    cout << ans << '\n';
  }
  
  return 0;
}
