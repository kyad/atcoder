#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long D;
  cin >> N >> D;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long A, B;
    cin >> A >> B;
    long long now = A + B * D;
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
