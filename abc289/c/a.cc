#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> S(M, 0);
  for (int m = 0; m < M; m++) {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
      int a;
      cin >> a;
      a--;
      S[m] |= (1<<a);
    }
  }
  int ans = 0;
  for (int bit = 1; bit < (1<<M); bit++) {
    int now = 0;
    for (int m = 0; m < M; m++) {
      if ((bit>>m)&1) {
        now |= S[m];
      }
    }
    if (now == ((1<<N) - 1)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
