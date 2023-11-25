#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<long long> R(N, 0), C(N, 0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (S[i][j] == 'o') {
        R.at(i)++;
        C.at(j)++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (S[i][j] == 'o' && R.at(i) >= 2 && C.at(j) >= 2) {
        long long now = (R.at(i) - 1) * (C.at(j) - 1);
        ans += now;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
