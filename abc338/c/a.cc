#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> Q(N);
  for (int n = 0; n < N; n++) {
    cin >> Q.at(n);
  }
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  // Aの最大数
  const int INF = 1e9;
  int Xmax = INF;
  for (int i = 0; i < N; i++) {
    if (A.at(i) == 0) {
      continue;
    }
    int now = Q.at(i) / A.at(i);
    Xmax = min(Xmax, now);
  }
  assert(Xmax < INF);
  int ans = -1;
  for (int x = 0; x <= Xmax; x++) {  // x: Aを作る個数
    vector<int> R(N);
    for (int i = 0; i < N; i++) {
      R.at(i) = Q.at(i) - A.at(i) * x;
      assert(R.at(i) >= 0);
    }

    int y = INF;  // y: Bを作る個数
    for (int i = 0; i < N; i++) {
      if (B.at(i) == 0) {
        continue;
      }
      y = min(y, R.at(i) / B.at(i));
    }
    assert(y < INF);

    int now = x + y;
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
