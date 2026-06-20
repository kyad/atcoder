#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > XY(N);
  for (int i = 0; i < N; i++) {
    int X, Y;
    cin >> X >> Y;
    XY.at(i) = make_pair(X, Y);
  }
  sort(XY.begin(), XY.end());
  int ymin = 1e9;
  int ans = 0;
  for (auto [x, y] : XY) {
    if (y < ymin) {
      ans++;
    }
    ymin = min(ymin, y);
  }
  cout << ans << endl;
  return 0;
}
