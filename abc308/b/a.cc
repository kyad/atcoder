#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> C(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
  }
  vector<string> D(M);
  for (int m = 0; m < M; m++) {
    cin >> D.at(m);
  }
  vector<int> P(M + 1, 0);
  for (int m = 0; m <= M; m++) {
    cin >> P.at(m);
  }
  map<string, int> mp;
  for (int m = 0; m < M; m++) {
    mp[D[m]] = P[m + 1];
  }
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    string color = C[n];
    int now;
    if (mp.count(color) > 0) {
      now = mp[color];
    } else {
      now = P[0];
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
