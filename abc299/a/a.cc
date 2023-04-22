#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int l = -1;
  int r = -1;
  int t = -1;
  for (int n = 0; n < N; n++) {
    if (S[n] == '|') {
      if (l < 0) {
        l = n;
      } else {
        r = n;
      }
    } else if (S[n] == '*') {
      t = n;
    }
  }
  assert(l >= 0);
  assert(r >= 0);
  assert(t >= 0);
  assert(l < r);
  if (l < t && t < r) {
    cout << "in" << endl;
  } else {
    cout << "out" << endl;
  }
  return 0;
}
