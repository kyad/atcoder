#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  vector<pair<int, int> > A(N);
  for (int n = 0; n < N; n++) {
    A[n] = make_pair(P[n], n);
  }
  sort(A.begin(), A.end());
  int ans = 0;
  int mx = -1;
  for (int i = 0; i < N; i++) {
    int S = A[i].second;
    if (S > mx) {
      mx = S;
      ans++;
    }
  }
  cout << ans << '\n';
  return;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
