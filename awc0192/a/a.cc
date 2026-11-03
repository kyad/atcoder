#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long A, B;
  cin >> N >> A >> B;
  long long ans = A;
  for (int i = 0; i < N; i++) {
    cout << ans << '\n';
    ans += B;
  }
  return 0;
}
