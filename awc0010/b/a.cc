#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i);
  }
  long long ans = D.at(0);
  for (int i = 1; i < N; i++) {
    if (D.at(i - 1) < D.at(i)) {
      ans += D.at(i) / 2;
    } else {
      ans += D.at(i);
    }
  }
  cout << ans << '\n';
  return 0;
}
