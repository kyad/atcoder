#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int ans;
  if (A == B) {
    ans = 1;
  } else if (abs(B - A) % 2 == 0) {
    ans = 3;
  } else {
    ans = 2;
  }
  cout << ans << endl;
  return 0;
}
