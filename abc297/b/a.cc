#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  // 1
  int x = -1;
  int y = -1;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'B') {
      if (x < 0) {
        x = n;
      } else {
        y = n;
      }
    }
  }
  assert(x >= 0);
  assert(y >= 0);
  if ((x + y) % 2 == 0) {
    cout << "No" << endl;
    return 0;
  }

  // 2
  {
    int x = -1;
    int y = -1;
    int z = -1;
    for (int n = 0; n < N; n++) {
      if (S[n] == 'R') {
        if (x < 0) {
          x = n;
        } else {
          y = n;
        }
      } else if (S[n] == 'K') {
        z = n;
      }
    }
    assert(x >= 0);
    assert(y >= 0);
    assert(z >= 0);
    if (x < z && z < y) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
