#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    multiset<long long> st;
    for (int i = 0; i < N; i++) {
      cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
      long long b;
      cin >> b;
      st.insert(b);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    long long ans = 0;
    int i = 0;
    for (i = 0; i < N; i++) {
      long long a = A.at(i);
      long long b = 0;
      auto it = st.lower_bound(M - a);
      if (it != st.end()) {  // 見つかった時
        b = *it;
        st.erase(it);
      } else {
        break;
      }
      long long now = (a + b) % M;
      ans += now;
    }
    // のこり
    int res = N - i;
    vector<long long> B;
    for (long long b : st) {
      B.push_back(b);
    }
    assert((int)B.size() == res);
    for (int j = 0; j < res; j++) {
      long long now = (A.at(i + j) + B.at(j)) % M;
      ans += now;
    }
    cout << ans << '\n';
  }
  return 0;
}
