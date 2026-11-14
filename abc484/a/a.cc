#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int B, R;
  cin >> B >> R;
  int ans = (30 - B) * (30 - R);
  cout << ans << '\n';
  return 0;
}
