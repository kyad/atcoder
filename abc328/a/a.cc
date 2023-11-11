#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int S;
    cin >> S;
    if (S <= X) {
      ans += S;
    }
  }
  cout << ans << endl;
  return 0;
}
