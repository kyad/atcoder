#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N + 1, 0), X(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    A.at(i) = i;
    X.at(i) = i;
  }
  vector<int> P(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    P.at(i) = i;
  }
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, a;
      cin >> i >> a;
      int z = X.at(a);
      P.at(i) = z;
    } else if (type == 2) {
      int a, b;
      cin >> a >> b;
      int x = X.at(a);
      int y = X.at(b);
      X.at(a) = y;
      X.at(b) = x;
      A.at(y) = a;
      A.at(x) = b;
    } else {
      int i;
      cin >> i;
      int x = P.at(i);
      int a = A.at(x);
      cout << a << '\n';
    }
  }
  return 0;
}
