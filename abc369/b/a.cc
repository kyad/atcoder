#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int l = -1;
  int r = -1;
  int suml = 0;
  int sumr = 0;
  for (int i = 0; i < N; i++) {
    int A;
    char S;
    cin >> A >> S;
    if (S == 'L') {
      if (l >= 0) {
        suml += abs(A - l);
      }
      l = A;
    } else {
      if (r >= 0) {
        sumr += abs(A - r);
      }
      r = A;
    }
  }
  int ans = suml + sumr;
  cout << ans << endl;
  return 0;
}
