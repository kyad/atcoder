#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  string S;
  cin >> S;
  for (int d = 0; d < D; d++) {
    for (int i = N - 1; i >= 0; i--) {
      if (S.at(i) == '@') {
        S.at(i) = '.';
        break;
      }
    }
  }
  cout << S << endl;
  return 0;
}
