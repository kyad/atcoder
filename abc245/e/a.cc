#include <algorithm>
#include <iostream>
#include <tuple>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N), C(M), D(M);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  for (int m = 0; m < M; m++) {
    cin >> C.at(m);
  }
  for (int m = 0; m < M; m++) {
    cin >> D.at(m);
  }
  vector<tuple<int, int, bool> > pt;
  for (int n = 0; n < N; n++) {
    pt.push_back(make_tuple(B[n], A[n], false));
  }
  // box
  for (int m = 0; m < M; m++) {
    pt.push_back(make_tuple(D[m], C[m], true));
  }
  sort(pt.begin(), pt.end());
  multiset<int> st;
  bool ans = true;
  for (int i = N + M - 1; i >= 0; i--) {
    int x = get<0>(pt[i]);
    int y = get<1>(pt[i]);
    bool box = get<2>(pt[i]);
    if (box) {
      st.insert(y);
    } else {
      multiset<int>::iterator it = st.lower_bound(y);
      if (it == st.end()) {
        ans = false;
        break;
      }
      st.erase(it);
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
