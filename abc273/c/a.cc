#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  set<int> st;
  vector<int> B;
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    if (st.count(A.at(n)) == 0) {
      B.push_back(A.at(n));
      st.insert(A.at(n));
    }
  }
  sort(B.begin(), B.end());
  vector<int> ans(N, 0);
  for (int i = 0; i < N; i++) {
    auto it = upper_bound(B.begin(), B.end(), A[i]);
    int now = distance(it, B.end());
    ans[now]++;
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
