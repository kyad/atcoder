#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, V;
  cin >> N >> V;
  vector<int> W(N);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        int v = i + j + k + 3;
        if (v > V) {
          continue;
        }
        int now = W.at(i) + W.at(j) + W.at(k);
        ans = max(ans, now);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
