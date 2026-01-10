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
  int N;
  cin >> N;
  vector<pair<int, int> > Ti(N);
  for (int i = 0; i < N; i++) {
    int T;
    cin >> T;
    Ti.at(i) = make_pair(T, i);
  }
  sort(Ti.begin(), Ti.end());
  vector<int> ans(3);
  for (int i = 0; i < 3; i++) {
    ans.at(i) = (Ti.at(i).second + 1);
  }
  dump(ans);
  return 0;
}
