#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  int H, W;
  cin >> H >> W;
  if (H > W) {
    swap(H, W);
  }
  // H <= W
  if (H == 1) {
    cout << W << endl;
    return 0;
  }
  cout << ceildiv(H, 2) * ceildiv(W, 2) << endl;
  return 0;
}
