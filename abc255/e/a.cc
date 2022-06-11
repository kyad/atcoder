#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> S(N - 1);
  for (int n = 0; n < N - 1; n++) {
    cin >> S.at(n);
  }
  vector<int> X(M);
  for (int m = 0; m < M; m++) {
    cin >> X.at(m);
  }
  vector<long long> T(N);
  T.at(0) = 0;
  for (int i = 1; i <= N - 1; i++) {
    T.at(i) = S.at(i - 1) - T.at(i - 1);
  }
  map<long long, int> mp;
  for (int k = 0; k < N; k++) {
    for (int j = 0; j < M; j++) {
      long long now = X.at(j) - T.at(k);
      if (k % 2) {
        now = -now;
      }
      mp[now]++;
    }
  }
  int ans = 0;
  for (map<long long, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    ans = max(ans, it->second);
  }
  cout << ans << endl;     
  return 0;
}
