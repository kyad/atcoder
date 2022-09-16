// https://atcoder.jp/contests/arc148/tasks/arc148_a

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int mx = *max_element(A.begin(), A.end());
  int ans = 1e9;
  for (int i = 2; i <= mx + 1; i++) {
    set<int> st;
    for (int n = 0; n < N; n++) {
      st.insert(A[n] % i);
    }
    ans = min(ans, (int)st.size());
  }
  cout << ans << endl;
  return 0;
}
