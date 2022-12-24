#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  const int INF = 1e9+1;
  for (int i = 1; i <= N; i++) {
    int ans = INF;
    for (int delta = 1; delta <= N; delta++) {
      if (delta >= ans) {
        break;
      }
      const int d[2] = {1, -1};
      for (int k = 0; k < 2; k++) {
        int j = i + d[k] * delta;
        if (j < 1 || j > N) {
          continue;
        }
        ans = min(ans, delta + abs(P[i] - P[j]));
      }
    }
    //cout << ans << (i == N ? '\n' : ' ');
    cout << ans << ' ';
  }
  cout << endl;
  return 0;
}
