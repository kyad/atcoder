#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (B > A) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
