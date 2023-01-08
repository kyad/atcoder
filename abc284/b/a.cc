#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  int ans = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    if (A % 2) {
      ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
