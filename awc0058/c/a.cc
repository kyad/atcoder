#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> imos(N + 1, 0);
  for (int j = 0; j < M; j++) {
    int L, R;
    cin >> L >> R;
    L--; R--;
    imos.at(L)++;
    imos.at(R + 1)--;
  }
  for (int i = 1; i <= N; i++) {
    imos.at(i) += imos.at(i - 1);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (imos.at(i) >= K) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
