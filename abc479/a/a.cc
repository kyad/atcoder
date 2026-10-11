#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      ans += A.at(i);
    }
  }
  cout << ans << '\n';
  return 0;
}
