#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N), B(N);  // A[p]: 鳩の場所、B[h]: 巣hの鳩の数
  for (int i = 0; i < N; i++) {
    A.at(i) = i;
    B.at(i) = 1;
  }
  int ans = 0;  // 複数の鳩がいる巣の数
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int P, H;
      cin >> P >> H;
      P--; H--;
      int prev = A.at(P);
      if (B.at(prev) == 2) {
        ans--;
      }
      B.at(prev)--;
      A.at(P) = H;
      B.at(H)++;
      if (B.at(H) == 2) {
        ans++;
      }
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
