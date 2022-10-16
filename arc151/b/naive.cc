#include <iostream>
#include <set>
#include <vector>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  mint ans = 0;
  auto solve = [&](vector<int> A) {
    vector<int> B(N);
    for (int n = 0; n < N; n++) {
      B.at(n) = A.at(P.at(n));
    }
    return B;
  };
  vector<int> A;
  auto dfs = [&](auto dfs, int depth) -> void {
    if (depth == N) {
      auto B = solve(A);
      if (A < B) {
        ans++;
      }
      return;
    }
    for (int v = 1; v <= M; v++) {
      A.push_back(v);
      dfs(dfs, depth + 1);
      A.pop_back();
    }
  };
  dfs(dfs, 0);
  cout << ans.val() << endl;
  return 0;
}
