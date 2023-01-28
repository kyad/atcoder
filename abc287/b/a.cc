#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    string now;
    cin >> now;
    S[n] = now.substr(3, 3);
  }
  vector<string> T(M);
  for (int m = 0; m < M; m++) {
    cin >> T.at(m);
  }
  int ans = 0;
  for (int n = 0; n < N; n++) {
    bool ok = false;
    for (int m = 0; m < M; m++) {
      if (S[n] == T[m]) {
        ok = true;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
