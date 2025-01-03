#include <algorithm>
#include <cassert>
#include <iostream>
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
  // 初項がa以上で長さnの列を列挙する
  auto f = [&](auto f, int n, int a) -> vector<vector<int> > {
    vector<vector<int> > ans;
    if (n == 0) {
      ans.push_back(vector<int>());
      return ans;
    }
    for (int b = a; b <= M - 10 * (n - 1); b++) {  // b: 今の初項
      for (vector<int>& v: f(f, n - 1, b + 10)) {
        v.insert(v.begin(), b);
        ans.push_back(v);
      }
    }
    return ans;
  };
  vector<vector<int> > vs = f(f, N, 1);
  int K = vs.size();
  cout << K << endl;
  for (vector<int>& v : vs) {
    dump(v);
  }
  return 0;
}
