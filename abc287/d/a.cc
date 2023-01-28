#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> solve(string S, string T) {
  int N = T.size() + 1;
  vector<bool> ans(N, false);
  ans[0] = true;
  for (int x = 1; x < N; x++) {
    if (ans[x - 1] == false) {
      ans[x] = false;
      continue;
    }
    if (T[x - 1] == S[x - 1]) {
      ans[x] = true;
      continue;
    }
    if (S[x - 1] == '?' || T[x - 1] == '?') {
      ans[x] = true;
      continue;
    }
    ans[x] = false;
  }
  return ans;
}

int main() {
  string S, T;
  cin >> S >> T;
  vector<bool> pre = solve(S, T);
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  vector<bool> suf = solve(S, T);
  reverse(suf.begin(), suf.end());
  for (size_t x = 0; x < pre.size(); x++) {
    bool ans = pre[x] && suf[x];
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
