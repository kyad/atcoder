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
  int N, D;
  cin >> N >> D;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
  }
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    bool ok = true;
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      int dist = abs(X.at(i) - X.at(j));
      if (dist < D) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans.push_back(i + 1);
    }
  }
  int K = ans.size();
  cout << K << '\n';
  if (K == 0) {
    cout << endl;
  } else {
    dump(ans);
  }
  return 0;
}
