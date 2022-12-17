#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  int ans = 0;
  for (int x = 0; x < N; x++) {
    for (int y = x + 1; y < N; y++) {
      bool now = true;
      for (int m = 0; m < M; m++) {
        if (S[x][m] == 'o' || S[y][m] == 'o') {
        } else {
          now = false;
        }
      }
      if (now) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
