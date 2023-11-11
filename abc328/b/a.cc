#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int g(int x) {
  int value;
  if (x >= 100) {
    return -1;
  } else if (x >= 10) {
    if (x % 11 != 0) {
      return -1;
    }
    value = x / 11;
  } else {
    value = x;
  }
  return value;
}

bool f(int m, int d) {
  int mm = g(m);
  if (mm < 0) {
    return false;
  }
  int dd = g(d);
  if (dd < 0) {
    return false;
  }
  if (mm != dd) {
    return false;
  }
  return true;
}
   

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int m = 1; m <= N; m++) {
    int D;
    cin >> D;
    for (int d = 1; d <= D; d++) {
      if (f(m, d)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
