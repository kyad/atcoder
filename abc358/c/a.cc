#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  const int N2 = 1 << N;
  int ans = 999;
  for (int bit = 0; bit < N2; bit++) {
    vector<bool> sell(M, false);
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {
        for (int j = 0; j < M; j++) {
          if (S.at(i).at(j) == 'o') {
            sell.at(j) = true;
          }
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < M; j++) {
      if (!sell.at(j)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans = min(ans, __builtin_popcount(bit));
    }
  }
  cout << ans << endl;
  return 0;
}
