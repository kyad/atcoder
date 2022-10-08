#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> even, odd;
  for (int n = 0; n < N; n++) {
    long long A;
    cin >> A;
    if (A % 2) {
      odd.push_back(A);
    } else {
      even.push_back(A);
    }
  }
  sort(odd.begin(), odd.end());
  reverse(odd.begin(), odd.end());
  sort(even.begin(), even.end());
  reverse(even.begin(), even.end());
  long long ans = -1;
  if (odd.size() >= 2) {
    ans = max(ans, odd[0] + odd[1]);
  }
  if (even.size() >= 2) {
    ans = max(ans, even[0] + even[1]);
  }
  cout << ans << endl;
  return 0;
}
