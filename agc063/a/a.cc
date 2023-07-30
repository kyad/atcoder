#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  queue<int> iA;
  queue<int> iB;
  for (int i = 0; i <= N; i++) {
    if (S.at(i) == 'A') {
      iA.push(i);
    } else {
      iB.push(i);
    }
  }
  int mex = 0;
  set<int> st;
  for (int k = 1; k <= N; k++) {
    if (k % 2) {  // Alice
      if (!iB.empty()) {
        int i = iB.front();
        iB.pop();
        st.insert(i);
      }
    } else {
      if (!iA.empty()) {
        int i = iA.front();
        iA.pop();
        st.insert(i);
      }
    }
    while (st.count(mex) >= 1) {
      mex++;
    }
    assert(0 <= mex && mex <= N);
    string ans;
    if (S.at(mex) == 'A') {
      ans = "Alice";
    } else {
      ans = "Bob";
    }
    cout << ans << '\n';
  }
  return 0;
}
