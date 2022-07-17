#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<long long> red(N + 1, 0), blue(N + 1, 0);
  red[N] = 1;
  for (int n = N; n > 1; n--) {
    // red n
    red[n - 1] += red[n];
    blue[n] += red[n] * X;
    // blue n
    red[n - 1] += blue[n];
    blue[n - 1] += blue[n] * Y;
  }
  cout << blue[1] << endl;
  return 0;
}
