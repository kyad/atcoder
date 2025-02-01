// https://www.youtube.com/watch?v=nXr0mN-HyOA&t=3895s

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  unordered_set<long long> st;
  vector<vector<int> > X;
  auto dfs = [&](auto dfs, int n) {
    if (n == N) {
      long long now = 0;
      for (auto is : X) {
        long long sum = 0;
        for (int i: is) {
          sum += A.at(i);
        }
        now ^= sum;
      }
      st.insert(now);
      return;
    }
    int K = X.size();
    // 既存グループに入れるとき
    for (int k = 0; k < K; k++) {
      X.at(k).push_back(n);
      dfs(dfs, n + 1);
      X.at(k).pop_back();
    }
    // 新規グループを作るとき
    X.push_back({n});
    dfs(dfs, n + 1);
    X.pop_back();
  };
  dfs(dfs, 0);
  int ans = st.size();
  cout << ans << endl;
  return 0;

}