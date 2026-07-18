#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  bool ans = W * 10000 >= 25 * H * H;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
