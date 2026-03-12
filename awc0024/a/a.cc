#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  for (int qi = 0; qi < Q; qi++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    bool ans = S.at(a) > S.at(b);
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
