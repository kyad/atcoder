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
  set<int> nx;
  for (int i = 0; i <= N - M; i++) {
    st.insert(i);
    nx.insert(i);
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
  for (int j = 0; j < N + 10; j++) {
    vector<int> removed;
    for (int i : nx) {
      if (f(i)) {
        removed.push_back(i);
      }
    }
    if (removed.empty()) {
      cout << "No" << endl;
      return 0;
    }
    for (int i : removed) {
      st.erase(i);
    }
    if (st.empty()) {
      cout << "Yes" << endl;
      return 0;
    }
    // fill & next
    set<int> fills;
    for (int i : removed) {
      for (int m = 0; m < M; m++) {
        fills.insert(i + m);
      }
    }
    nx.clear();
    for (int i : fills) {
      S.at(i) = '*';
      for (int j = i - M + 1; j <= i + M - 1; j++) {
        if (st.count(j) > 0) {
          nx.insert(j);
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
