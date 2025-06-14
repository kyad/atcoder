#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> vector<T> set2vector(const set<T> &s) {
  vector<T> v;
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    v.push_back(*it);
  }
  return v;
}

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  set<int> st;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    st.insert(A);
  }
  vector<int> C = set2vector(st);
  int M = C.size();
  cout << M << endl;
  dump(C);
  return 0;
}
