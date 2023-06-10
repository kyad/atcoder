#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans;
  if (N % 5 <= 2) {
    ans = N - N % 5;
  } else {
    ans = N + 5 - (N % 5);
  }
  cout << ans << endl;
  return 0;
}
