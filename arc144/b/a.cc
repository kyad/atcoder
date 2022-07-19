// https://atcoder.jp/contests/arc144/tasks/arc144_b

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, a, b;
  cin >> N >> a >> b;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int left = 0;  // OK
  int right = 1000000001;  // NG
  while (right - left > 1) {
    int x = (left + right) / 2;
    long long ca = 0;
    long long cb = 0;
    for (int n = 0; n < N; n++) {
      if (A.at(n) < x) {
        ca += (x - A.at(n) + a - 1) / a;
      } else if (A.at(n) > x) {
        cb += (A.at(n) - x) / b;
      }
    }
    if (ca <= cb) {  // OK
      left = x;
    } else {
      right = x;
    }
  }
  cout << left << endl;
  return 0;
}
