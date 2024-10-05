#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  if (S == T) {
    cout << 0 << endl;
    return 0;
  }
  int N = min(S.size(), T.size());
  int i = 0;
  for (i = 0; i < N; i++) {
    if (S.at(i) != T.at(i)) {
      break;
    }
  }
  int ans = i + 1;
  cout << ans << endl;
  return 0;
}
