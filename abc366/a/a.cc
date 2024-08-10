#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;
  int th = N / 2 + 1;
  bool ans = (T >= th) || (A >= th);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
