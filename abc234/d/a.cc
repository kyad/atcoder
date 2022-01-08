#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  set<int> st;
  for (int n = 0; n < K; n++) {
    st.insert(P[n]);
  }
  int prev = *st.begin();
  // K
  cout << prev << endl;
  for (int n = K; n < N; n++) {
    st.insert(P[n]);
    if (P[n] > prev) {
      prev = *st.upper_bound(prev);
    }
    cout << prev << endl;
  }
  return 0;
}
