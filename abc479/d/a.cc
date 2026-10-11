#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, Q;
  cin >> N >> Q;
  const int INF = 1e9;
  vector<int> L(N, INF), R(N, INF);
  for (int i = 1; i < N; i++) {
    cin >> L.at(i);
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> R.at(i);
  }
  vector<int> cL(L), cR(R);
  for (int i = N - 2; i >= 0; i--) {
    chmin(cL.at(i), cL.at(i + 1));
  }
  for (int i = 1; i < N; i++) {
    chmin(cR.at(i), cR.at(i - 1));
  }
  for (int q = 0; q < Q; q++) {
    int s, t;
    cin >> s >> t;
    s--; t--;
    int ans;
    if (s < t) {
      ans = R.at(s);
      if (s >= 1) {
        chmin(ans, L.at(s) + cR.at(s - 1));
      }
    } else {
      ans = L.at(s);
      if (s <= N - 2) {
        chmin(ans, R.at(s) + cL.at(s + 1));
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
