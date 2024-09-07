#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;
  if (L + R == 1) {
    if (L == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    cout << "Invalid" << endl;
  }
  return 0;
}
