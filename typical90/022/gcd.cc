#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long long A, B, C;
  cin >> A >> B >> C;
  long long g = __gcd(A, B);
  g = __gcd(g, C);
  long long ans = A / g + B / g + C / g - 3;
  cout << ans << endl;
  return 0;
}
