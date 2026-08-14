#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long R;
  cin >> N >> R;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long mn = *min_element(A.begin(), A.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A.at(i) - mn;
  }
  cout << ans << '\n';
  return 0;
}
