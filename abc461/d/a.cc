#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H + 1);
  for (int y = 1; y <= H; y++) {
    cin >> S.at(y);
    S.at(y).insert(S.at(y).begin(), '_');
  }
  vector<vector<int> > A(H + 1, vector<int>(W + 1, 0));
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      if (S.at(y).at(x) == '1') {
        A.at(y).at(x) = 1;
      }
    }
  }
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      A.at(y).at(x) += A.at(y).at(x - 1);
    }
  }
  for (int x = 1; x <= W; x++) {
    for (int y = 1; y <= H; y++) {
      A.at(y).at(x) += A.at(y - 1).at(x);
    }
  }
  long long ans = 0;
  for (int r1 = 1; r1 <= H; r1++) {
    for (int r2 = r1; r2 <= H; r2++) {
      vector<int> D(W + 1, 0);
      for (int i = 1; i <= W; i++) {
         D.at(i) = A.at(r2).at(i) - A.at(r1 - 1).at(i);
      }
      for (int i = 0; i <= W - 1; i++) {
        int x = D.at(i);
        int r = upper_bound(D.begin(), D.end(), x + K) - D.begin();
        int l = lower_bound(D.begin(), D.end(), x + K) - D.begin();
        l = max(i + 1, l);
        long long now = r - l;
        ans += now;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
