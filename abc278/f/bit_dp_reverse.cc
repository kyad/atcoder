// https://atcoder.jp/contests/abc278/tasks/abc278_f

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<char> first(N), last(N);
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    int len = S.size();
    first[n] = S[0];
    last[n] = S[len - 1];
  }
  int M = 1<<N;
  // dp[s][j]: 既に選ばれている単語がsで、最後がjの時に0=自分が負ける、1=相手が勝つ
  vector<vector<int> > dp(M, vector<int>(N, -1));

  auto solve = [&](int s, int j) {
    if (s == M - 1) {  // 初期条件
      return 0;
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (((s >> i) & 1) == 1) {
        continue;
      }
      if (j >= 0 && last[j] != first[i]) {
        continue;
      }
      int ns = s | (1<<i);
      int now = dp[ns][i];
      assert(now >= 0);  // sをM-1から0に変化させる方向でも、dp[ns][i]は既に求まっているからbit DPできる
      if (now == 0) {
        ans = 1;
      }
    }
    return ans;
  };

  for (int s = M - 1; s > 0; s--) {
    for (int j = 0; j < N; j++) {
      if (((s>>j)&1) == 0) {
        continue;
      }
      dp[s][j] = solve(s, j);
    }
  }
  int ans = solve(0, -1);
  if (ans == 1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
