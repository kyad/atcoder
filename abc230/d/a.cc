#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<pair<int, int> > RL(N);
  for (int n = 0; n < N; n++) {
    int L, R;
    cin >> L >> R;
    RL.at(n) = make_pair(R, L);
  }
  sort(RL.begin(), RL.end());
  int R0 = RL[0].first;
  int left = R0;
  int right = left + D - 1;
  int ans = 1;
  for (int n = 1; n < N; n++) {
    int L = RL[n].second;
    int R = RL[n].first;
    if (L <= right) {
      continue;
    }
    left = R;
    right = left + D - 1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
