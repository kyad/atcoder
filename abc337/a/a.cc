#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int X = 0;
  int Y = 0;
  for (int n = 0; n < N; n++) {
    int x, y;
    cin >> x >> y;
    X += x;
    Y += y;
  }
  string ans = "Draw";
  if (X > Y) {
    ans = "Takahashi";
  } else if (X < Y) {
    ans = "Aoki";
  }
  cout << ans << endl;
  return 0;
}
