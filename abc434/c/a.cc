#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N;
    long long H;
    cin >> N >> H;
    long long a = H;
    long long b = H;
    int t = 0;
    bool ans = true;
    for (int i = 0; i < N; i++) {
      int nt;
      long long l, u;
      cin >> nt >> l >> u;
      b = min(b + (nt - t), u);
      a = max(a - (nt - t), l);
      a = max(a, 0LL);
      if (b < a) {
        ans = false;
      }
      t = nt;
    }
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
