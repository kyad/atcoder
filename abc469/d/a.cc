#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int j = 0; j < M; j++) {
    cin >> A.at(j) >> B.at(j);
  }
  auto f = [&](int C) -> vector<pair<int, int>> {
    bool ok = true;
    for (int j = 1; j < M; j++) {
      if (C == A.at(j) || C == B.at(j)) {
        // ok
      } else {
        ok = false;
        break;
      }
    }
    if (ok) {
      vector<pair<int, int>> ans;
      for (int u = 1; u <= N; u++) {
        if (C != u) {
          int mn = min(C, u);
          int mx = max(C, u);
          ans.push_back(make_pair(mn, mx));
        }
      }
      return ans;
    }

    set<int> st;
    bool init = false;
    for (int j = 1; j < M; j++) {
      if (C == A.at(j) || C == B.at(j)) {
        // ok
        continue;
      }
      if (!init) {
        st.insert(A.at(j));
        st.insert(B.at(j));
        init = true;
        continue;
      }
      if (st.empty()) {
        continue;
      }
      vector<int> removes;
      for (int u : st) {
        if (u == A.at(j) || u == B.at(j)) {
          // ok
        } else {
          removes.push_back(u);
        }          
      }
      for (int u : removes) {
        st.erase(u);
      }
    }
    vector<pair<int, int>> ans;
    for (int u : st) {
      if (C != u) {
        int mn = min(C, u);
        int mx = max(C, u);
        ans.push_back(make_pair(mn, mx));
      }
    }
    return ans;
  };

  vector<pair<int, int>> a = f(A.at(0));
  vector<pair<int, int>> b = f(B.at(0));
  set<pair<int, int>> st;
  for (auto [u, v] : a) {
    st.insert(make_pair(u, v));
  }
  for (auto [u, v] : b) {
    st.insert(make_pair(u, v));
  }
  cout << st.size() << endl;
  return 0;
}
