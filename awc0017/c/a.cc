#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> C(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> C.at(i);
  }
  vector<int> D(N, 0);
  for (int i = 1; i <= N - 1; i++) {
    if (C.at(i) == C.at(i + 1)) {
      D.at(i) = 1;
    }
  }
  vector<int> S(D);
  for (int i = 1; i < N; i++) {
    S.at(i) += S.at(i - 1);
  }
  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    cin >> L >> R;
    int ans = S.at(R - 1) - S.at(L - 1);
    cout << ans << '\n';
  }
  return 0;
}
