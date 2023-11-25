#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  int ans = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    if (A >= L) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
