#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 8;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  vector<vector<bool> > color(N, vector<bool>(N, false));  // rookが取れるマスがtrue
  for (int ry = 0; ry < N; ry++) {
    for (int rx = 0; rx < N; rx++) {
      if (S.at(ry).at(rx) != '#') {
        continue;
      }
      // rookのチェック
      for (int y = 0; y < N; y++) {
        color.at(y).at(rx) = true;
      }
      for (int x = 0; x < N; x++) {
        color.at(ry).at(x) = true;
      }
    }
  }
  int ans = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (color.at(y).at(x) == false) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
