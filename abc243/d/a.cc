#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N;
  long long X;
  cin >> N >> X;
  string S;
  cin >> S;
  string T;
  stack<char> st;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'U') {
      if (st.empty()) {
        T.push_back('U');
      } else {
        st.pop();
      }
    } else {
      st.push(S[n]);
    }
  }
  string U;
  while (!st.empty()) {
    U.push_back(st.top());
    st.pop();
  }
  reverse(U.begin(), U.end());
  T += U;
  long long ans = X;
  for (size_t i = 0; i < T.size(); i++) {
    if (T[i] == 'U') {
      ans /= 2;
    } else if (T[i] == 'L') {
      ans *= 2;
    } else {
      ans = ans * 2 + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
