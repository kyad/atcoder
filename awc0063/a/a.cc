#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<pair<int, int> > ans;
  for (int y = 0; y < H; y++) {
    string S;
    cin >> S;
    for (int x = 0; x < W; x++) {
      if (S.at(x) == 'T') {
        ans.push_back(make_pair(y + 1, x + 1));
      }
    }
  }
  int K = ans.size();
  cout << K << '\n';
  for (auto [y, x] : ans) {
    cout << y << ' ' << x << '\n';
  }
  return 0;
}
