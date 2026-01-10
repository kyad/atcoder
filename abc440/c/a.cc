#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int N, W;
  cin >> N >> W;
  vector<long long> C;
  for (int i = 0; i < N; i++) {
    long long c;
    cin >> c;
    C.push_back(c);
  }
  if (N % (2 * W) != 0) {
    int count = 2 * W - N % (2 * W);
    for (int i = 0; i < count; i++) {
      C.push_back(0);
    }
  }
  int M = C.size();
  vector<long long> S(2 * W, 0);
  for (int j = 0; j < M; j++) {
    int k = j % (2 * W);
    S.at(k) += C.at(j);
  }
  // 最初
  long long sum = 0;
  for (int k = 0; k < W; k++) {
    sum += S.at(k);
  }
  long long ans = sum;
  for (int l = 1; l <= 2 * W; l++) {
    sum -= S.at((l - 1 + 2 * W) % (2 * W));
    sum += S.at((l + W - 1 + 2 * W) % (2 * W));
    ans = min(ans, sum);
  }
  cout << ans << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    solve();
  }
  return 0;
}
