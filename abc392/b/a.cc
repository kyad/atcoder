#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
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
  set<int> st;
  for (int j = 0; j < M; j++) {
    int A;
    cin >> A;
    st.insert(A);
  }
  vector<int> X;
  for (int i = 1; i <= N; i++) {
    if (!st.contains(i)) {
      X.push_back(i);
    }
  }
  int C = X.size();
  cout << C << endl;
  if (C > 0) {
    dump(X);
  } else {
    cout << endl;
  }
  return 0;
}
