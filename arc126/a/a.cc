#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long N2, N3, N4;
    cin >> N2 >> N3 >> N4;
    long long N6 = N3 / 2;
    long long ans = 0;
    long long a;

    a = min(N6, N4);
    ans += a;
    N6 -= a;
    N4 -= a;

    a = min(N6, N2 / 2);
    ans += a;
    N6 -= a;
    N2 -= a * 2;

    a = min(N4 / 2, N2);
    ans += a;
    N4 -= a * 2;
    N2 -= a;

    a = min(N4, N2 / 3);
    ans += a;
    N4 -= a;
    N2 -= a * 3;
    
    a = N2 / 5;
    ans += a;

    cout << ans << endl;
  }
  return 0;
}
