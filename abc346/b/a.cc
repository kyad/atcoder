#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string T = "wbwbwwbwbwbw";
  string S;
  for (int i = 0; i < 20; i++) {
    S += T;
  }
  int N = S.size();
  int W, B;
  cin >> W >> B;
  for (int i = 0; i < N; i++) {
    auto ii = S.begin() + i;
    for (int j = i + 1; j < N; j++) {
      auto jj = S.begin() + j;
      int w = count(ii, jj, 'w');
      int b = count(ii, jj, 'b');
      if (w == W && b == B) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
