// https://atcoder.jp/contests/arc144/tasks/arc144_a

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  cout << (2 * N) << endl;
  string x;
  while (N > 0) {
    int a = min(N, 4);
    N -= a;
    x.push_back('0' + a);
  }
  reverse(x.begin(), x.end());
  cout << x << endl;
  return 0;
}
