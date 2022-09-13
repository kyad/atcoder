// https://atcoder.jp/contests/abc268/tasks/abc268_d

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  int res = 16;
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
    res -= S.at(n).size();
    res--;
  }
  res++;
  set<string> T;
  for (int m = 0; m < M; m++) {
    string t;
    cin >> t;
    T.insert(t);
  }
  sort(S.begin(), S.end());
  do {
    // u: _を置ける残りの数、d: 深さ
    string now;
    auto dfs = [&](auto dfs, int u, int d) -> bool {
      if (d == N - 1) {
        now += S[N - 1];
        assert(now.size() <= 16);
        if (now.size() <= 2) {
          return false;
        }
        if (T.count(now) == 0) {
          cout << now << endl;
          return true;
        } else {
          return false;
        }
      }
      string temp = now + S[d] + "_";
      for (int v = 0; v <= u; v++) {
        now = temp;
        for (int i = 0; i < v; i++) {
          now.push_back('_');
        }
        if (dfs(dfs, u - v, d + 1)) {
          return true;
        }
      }
      return false;
    };
    if (dfs(dfs, res, 0)) {
      return 0;
    }
  } while (next_permutation(S.begin(), S.end()));
  cout << -1 << endl;
  return 0;
}
