#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = N + 1 - K;
  cout << ans << '\n';
  return 0;
}
