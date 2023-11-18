#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S;
  cin >> T;
  set<int> st;
  for (int i = 0; i <= N - M; i++) {
    st.insert(i);
  }
  auto f = [&](int start) -> bool {
    for (int m = 0; m < M; m++) {
      int i = start + m;
      if (S.at(i) == '*' || S.at(i) == T.at(m)) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  };
  auto fill = [&](int start) {
    for (int m = 0; m < M; m++) {
      int i = start + m;
      S.at(i) = '*';
    }
  };
  while (true) {
    vector<int> removed;
    for (int i : st) {
      if (f(i)) {
        fill(i);
        removed.push_back(i);
      }
    }
    for (int i : removed) {
      st.erase(i);
    }
    if (removed.empty()) {
      cout << "No" << endl;
      return 0;
    }
    if (st.empty()) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
