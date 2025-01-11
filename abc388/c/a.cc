#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long now = A.end() - lower_bound(A.begin(), A.end(), A.at(i) * 2);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
