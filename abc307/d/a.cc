#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  stack<string> st;
  string null = "";
  st.push(null);
  string now;
  for (int n = 0; n < N; n++) {
    assert(st.size() >= 1);
    char c = S.at(n);
    if (c == '(') {
      string null = "";
      st.push(null);
    } else if (c == ')') {
      if (st.size() == 1) {
        st.top() += c;
      } else {
        st.pop();
      }
    } else {
      st.top() += c;
    }
  }
  vector<string> T;
  while (!st.empty()) {
    T.push_back(st.top());
    st.pop();
    if (st.size() >= 1) {
      string now = "(";
      T.push_back(now);
    }
  }
  reverse(T.begin(), T.end());
  string ans;
  for (string now : T) {
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
