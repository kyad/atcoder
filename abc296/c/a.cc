#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  set<int> st;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    st.insert(A[n]);
  }
  bool ans = false;
  for (int n = 0; n < N; n++) {
    if (st.count(A[n] + X) > 0) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
