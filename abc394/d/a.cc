#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  stack<char> st;
  for (char c : S) {
    if (c == '(' || c == '[' || c == '<') {
      st.push(c);
    } else if (st.empty()) {
      st.push(c);
    } else {
      char d = st.top();
      if (d == '(' && c == ')') {
        st.pop();
      } else if (d == '[' && c == ']') {
        st.pop();
      } else if (d == '<' && c == '>') {
        st.pop();
      } else {
        st.push(c);
      }
    }
  }
  bool ans = st.empty();
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
