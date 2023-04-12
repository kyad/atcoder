#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P, Q;
  cin >> N >> P >> Q;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int ans = 0;
  vector<int> us;
  auto dfs = [&](auto dfs, int u) {
    if (us.size() == 5) {
      // check
      long long now = 1;
      for (int i = 0; i < 5; i++) {
        now *= A[us[i]];
        now %= P;
      }
      if (now == Q) {
        ans++;
      }
      return;
    }
    // 遷移
    for (int v = u + 1; v < N; v++) {
      us.push_back(v);
      dfs(dfs, v);
      us.pop_back();
    }
  };
  for (int u = 0; u < N; u++) {
    us.push_back(u);
    dfs(dfs, u);
    us.pop_back();
  }
  cout << ans << endl;
  return 0;
}
