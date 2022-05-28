#include <iostream>
using namespace std;

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  long long ans = 0;
  for (int n = 1; n <= N; n++) {
    if (n % A == 0) {
      continue;
    }
    if (n % B == 0) {
      continue;
    }
    ans += n;
  }
  cout << ans << endl;
  return 0;
}
