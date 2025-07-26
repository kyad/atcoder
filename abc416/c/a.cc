#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, X;
  cin >> N >> K >> X;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  vector<string> Ts;
  vector<int> A(K, -1);
  // k番目に置く
  auto dfs = [&](auto dfs, int k) -> void {
    if (k == K) { // 終了
      string T;
      for (int l = 0; l < K; l++) {
        int i = A.at(l);
        T += S.at(i);
      }
      Ts.push_back(T);
      return;
    }
    for (int i = 0; i < N; i++) {
      A.at(k) = i;
      dfs(dfs, k + 1);
    }
  };
  dfs(dfs, 0);
  sort(Ts.begin(), Ts.end());
  string ans = Ts.at(X - 1);
  cout << ans << endl;
  return 0;
}
