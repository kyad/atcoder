// https://atcoder.jp/contests/arc138/tasks/arc138_b

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T> &v) { int MOD = -1; int N = v.size(); os << '[';
  for (int i = 0; i < N; i++) { os << v[i];
    if (i == N - 1) { continue; }
    else if (MOD > 0 && i % MOD == (MOD - 1)) { os << '\n'; }
    else { os << ' '; }
  } os << ']'; return os; }

int solve(int N) {
  vector<vector<vector<int> > > a(N + 1);
  a[1].push_back({0});
  for (int n = 2; n <= N; n++) {
    for (vector<int> v : a[n - 1]) {
      vector<int> nowA;
      vector<int> nowB;
      nowA.push_back(0);
      for (int i : v) {
        nowA.push_back(1 - i);
        nowB.push_back(i);
      }
      nowB.push_back(0);
      a[n].push_back(nowA);
      a[n].push_back(nowB);
    }
    sort(a[n].begin(), a[n].end());
    a[n].erase(unique(a[n].begin(), a[n].end()), a[n].end());
    for (auto v : a[n]) cout << v << endl;
  }
  return 0;
}

int main() {
  int N = 16;
  solve(N);
  return 0;
}
