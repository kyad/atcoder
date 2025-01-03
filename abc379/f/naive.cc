#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void naive() {
  int N, Q;
  cin >> N >> Q;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    cin >> L >> R;
    L--; R--;

    int maxH = 0;
    for (int i = L; i <= R; i++) {
      maxH = max(maxH, H.at(i));
    }
    int ans = 0;
    for (int i = R; i < N; i++) {
      if (H.at(i) > maxH) {
        ans++;
        maxH = H.at(i);
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  naive();
  return 0;
}
