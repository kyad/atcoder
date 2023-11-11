#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  stack<char> st;
  for (int i = 0; i < N; i++) {
    char c = S.at(i);
    st.push(c);
    if (st.size() >= 3) {
      string T;
      for (int j = 0; j < 3; j++) {
        T.push_back(st.top()); st.pop();
      }
      if (T != "CBA") {
        for (int j = 2; j >= 0; j--) {
          st.push(T.at(j));
        }
      }
    }
  }
  string ans;
  while (!st.empty()) {
    ans.push_back(st.top());
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
