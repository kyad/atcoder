#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    A.at(i) = i + 1;
  }
  int shift = 0;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      A.at((p + shift + N) % N) = x;
    } else if (type == 2) {
      int p;
      cin >> p;
      p--;
      cout << A.at((p + shift + N) % N) << '\n';
    } else {
      int k;
      cin >> k;
      shift += k;
      shift %= N;
    }
  }
  return 0;
}
