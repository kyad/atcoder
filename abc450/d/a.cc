#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  set<int> st;
  for (int i = 0; i < N; i++) {
    st.insert(A.at(i) % K);
  }
  vector<int> B;
  for (int s : st) {
    B.push_back(s);
  }
  int M = B.size();
  int ans = 0;
  if (M >= 2) {
    int mx = B.at(0) + K - B.at(M - 1);
    for (int i = 1; i <= M - 1; i++) {
      int now = B.at(i) - B.at(i - 1);
      mx = max(mx, now);
    }
    ans = K - mx;
  }
  cout << ans << '\n';
  return 0;
}
