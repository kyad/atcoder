#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  stack<int> st;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    st.push(A);
    while (st.size() >= 2) {
      int a1 = st.top();
      st.pop();
      int a2 = st.top();
      st.pop();
      if (a1 == a2) {
        st.push(a1 + 1);
        continue;
      }
      st.push(a2);
      st.push(a1);
      break;
    }
  }
  int ans = st.size();
  cout << ans << endl;
  return 0;
}
