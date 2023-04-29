#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int D = A + B;
  for (int n = 1; n <= N; n++) {
    int C;
    cin >> C;
    if (D == C) {
      cout << n << endl;
      break;
    }
  }
  return 0;
}
