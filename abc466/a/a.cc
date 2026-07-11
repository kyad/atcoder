#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool ans = true;
  for (int i = 0; i < N; i++) {
    int X;
    cin >> X;
    if (X >= 0) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
