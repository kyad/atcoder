#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  int ans = -1;
  for (int n = 0; n < N; n++) {
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), A[n] + M);
    int m = it - A.begin();
    int now = m - n;
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
