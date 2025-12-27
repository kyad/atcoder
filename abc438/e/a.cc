#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  // Doubling table
  int K = 32;
  vector<vector<int> > g(K, vector<int>(N + 1, 0));
  vector<vector<long long> > h(K, vector<long long>(N + 1, 0));
  for (int x = 1; x <= N; x++) {
    g.at(0).at(x) = A.at(x);
    h.at(0).at(x) = x;
  }
  for (int i = 1; i < K; i++) {
    for (int x = 1; x <= N; x++) {
      g.at(i).at(x) = g.at(i - 1).at(g.at(i - 1).at(x));
      h.at(i).at(x) = h.at(i - 1).at(x) + h.at(i - 1).at(g.at(i - 1).at(x));
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    int T, B;
    cin >> T >> B;
    int x = B;
    long long ans = 0;
    for (int i = 0; i < K; i++) {
      if (T >> i & 1) {
        ans += h.at(i).at(x);
        x = g.at(i).at(x);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
