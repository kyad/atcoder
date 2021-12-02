// https://atcoder.jp/contests/abc210/tasks/abc210_a

#include <iostream>
using namespace std;

int main() {
  int N, A, X, Y;
  cin >> N >> A >> X >> Y;
  int a = min(N, A);
  int b = max(N - a, 0);
  int ans = X * a + Y * b;
  cout << ans << endl;
  return 0;
}
  
