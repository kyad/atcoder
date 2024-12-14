#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  for (int i = 0; i < N; i++) {
    int D, A;
    cin >> D >> A;
    if (D == 1) {
      if (1600 <= R && R <= 2799) {
        R += A;
      }
    } else {
      if (1200 <= R && R <= 2399) {
        R += A;
      }
    }
  }
  int ans = R;
  cout << ans << endl;
  return 0;
}
