#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> S(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i) >> C.at(i);
  }
  vector<int> A(S);
  sort(A.begin(), A.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) < C.at(i)) {
      long long now = prev(lower_bound(A.begin(), A.end(), C.at(i))) - lower_bound(A.begin(), A.end(), S.at(i));
      ans += now;
    }
  }
  cout << ans << '\n';
  return 0;
}
