#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int n = N; n >= 1; n--) {
    cout << n;
    if (n != 1) {
      cout << ',';
    }
  }
  cout << '\n';
  return 0;
}
