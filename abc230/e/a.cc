#include <iostream>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  long long max = N;
  long long a = 1;
  while (true) {
    long long min = (long long)(N / (a + 1) + 1);
    ans += a * (max - min + 1);
    max = min - 1;
    if (max == 0) {
      break;
    }
    a = N / max;
  }
  cout << ans << endl;
  return 0;
}
