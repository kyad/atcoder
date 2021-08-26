// https://atcoder.jp/contests/abc095/tasks/arc096_a

#include <iostream>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int Z = min(X, Y);
  int ans = min(A * (X - Z) + B * (Y - Z) + C * Z * 2, A * X + B * Y);
  ans = min(ans, C * max(X, Y) * 2);
  cout << ans << endl;
  return 0;
}
