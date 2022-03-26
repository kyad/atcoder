#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> st;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    st.insert(A);
  }
  int ans = 0;
  for (ans = 0; ans <= 2001; ans++) {
    if (st.count(ans) > 0) {
      continue;
    }
    break;
  }
  cout << ans << endl;
  return 0;
}
