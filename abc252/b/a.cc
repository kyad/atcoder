#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(K);
  for (int k = 0; k < K; k++) {
    cin >> B.at(k);
    B.at(k)--;
  }
  set<int> st;
  int mx = *max_element(A.begin(), A.end());
  for (int n = 0; n < N; n++) {
    if (A.at(n) == mx) {
      st.insert(n);
    }
  }
  string ans = "No";
  for (int k = 0; k < K; k++) {
    if (st.count(B.at(k)) > 0) {
      ans = "Yes";
    }
  }
  cout << ans << endl;
  return 0;
}
