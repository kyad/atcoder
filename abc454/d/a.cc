#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string convert(string &S) {
  int N = S.size();
  stack<char> st;
  for (int i = 0; i < N; i++) {
    st.push(S.at(i));
    while (st.size() >= 4) {
      char d = st.top(); st.pop();
      char c = st.top(); st.pop();
      char b = st.top(); st.pop();
      char a = st.top(); st.pop();
      if (a == '(' && b == 'x' && c == 'x' && d == ')') {
        st.push(b); st.push(c);
      } else {
        st.push(a); st.push(b); st.push(c); st.push(d);
        break;
      }
    }
  }
  string ans;
  while (!st.empty()) {
    ans.push_back(st.top()); st.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    string A, B;
    cin >> A >> B;
    string P = convert(A);
    string Q = convert(B);
    bool ans = (P == Q);
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
