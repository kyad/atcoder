#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void f(vector<int> &H, int K, int D) {
  if (K == 1) {
    return;
  }
  int N = H.size();
  multiset<int> st;
  st.insert(H.at(0));
  for (int i = 1; i < K - 1; i++) {
    int mn = *st.begin();
    if (H.at(i) > mn + D) {
      int diff = H.at(i) - (mn + D);
      H.at(i) -= diff;
    }
    st.insert(H.at(i));
  }
  for (int i = 0; i <= N - K; i++) {
    int ni = i + K - 1;
    int mn = *st.begin();
    if (H.at(ni) > mn + D) {
      int diff = H.at(ni) - (mn + D);
      H.at(ni) -= diff;
    }
    st.insert(H.at(ni));
    st.erase(st.find(H.at(i)));
  }
}

int main() {
  int N, K, D;
  cin >> N >> K >> D;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  for (int k = 0; k < 10; k++) {
    f(H, K, D);
    reverse(H.begin(), H.end());
    f(H, K, D);
    reverse(H.begin(), H.end());
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += H.at(i);
  }
  cout << ans << '\n';
  return 0;
}

