#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  while (N > 0) {
    if (N % 2 == 1) {
      break;
    }
    ans++;
    N /= 2;
  }
  cout << ans << endl;
  return 0;
}
