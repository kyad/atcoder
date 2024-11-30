#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  map<vector<int>, vector<vector<int> > > memo;
  auto f = [&](auto f, int a0, int n) -> vector<vector<int> > {
    vector<int> key;
    key.push_back(a0);
    key.push_back(n);
    if (memo.contains(key)) {
      return memo[key];
    }
    vector<vector<int> > ans;
    if (n == 0) {
      ans.push_back(vector<int>());
      return memo[key] = ans;
    }
    for (int a = a0; a <= M - 10 * (n - 1); a++) {
      vector<vector<int> > vs = f(f, a + 10, n - 1);
      for (const vector<int> &v : vs) {
        vector<int> now;
        now.push_back(a);
        for (int b : v) {
          now.push_back(b);
        }
        ans.push_back(now);
      }
    }
    return memo[key] = ans;
  };

  vector<vector<int> > ans = f(f, 1, N);
  int K = ans.size();
  cout << K << endl;
  for (int k = 0; k < K; k++) {
    dump(ans.at(k));
  }
  return 0;
}
