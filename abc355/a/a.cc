#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ans = -1;
  if (A != B) {
    ans = 6 - A - B;
  }
  cout << ans << endl;
  return 0;
}
