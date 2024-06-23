#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> d(N, 1);
  set<pair<long long, int> > st; // (dc[i], i) // dc[i]: d[i]を1増やした時のコストの増分
  for (int i = 0; i < N; i++) {
    long long dc = (long long)(2 * d[i] + 1) * A[i]; // dを1増やした時のコストの増分
    st.insert(make_pair(dc, i));
  }
  for (int j = 0; j < N - 2; j++) {
    int i = st.begin()->second;
    d[i]++;
    long long ndc = (long long)(2 * d[i] + 1) * A[i];
    st.erase(st.begin());
    st.insert(make_pair(ndc, i));
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (long long)d[i] * d[i] * A[i];
  }
  cout << ans << endl;
  return 0;
}
