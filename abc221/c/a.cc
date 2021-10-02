#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<int> digits;
  int K = 0;
  while (N > 0) {
    K++;
    digits.push_back(N % 10);
    N /= 10;
  };
  long long ans = 0;
  for (int bit = 0; bit < (1<<K); bit++) {
    vector<int> a, b;
    for (int k = 0; k < K; k++) {
      if ((bit >> k) & 1) {
        a.push_back(digits[k]);
      } else {
        b.push_back(digits[k]);
      }
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    long long A = 0, B = 0;
    for (size_t i = 0; i < a.size(); i++) {
      A *= 10;
      A += a[i];
    }
    for (size_t i = 0; i < b.size(); i++) {
      B *= 10;
      B += b[i];
    }
    long long temp = A * B;
    ans = max(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
