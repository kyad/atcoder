#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int k = 2 * j - i;
      if (k >= N) {
        continue;
      }
      if (S.at(i) == 'A' && S.at(j) == 'B' && S.at(k) == 'C') {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
