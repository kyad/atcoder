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
  int ans = -1;
  int mx = -1;
  for (int i = 0; i < N; i++) {
    if (A.at(i) > mx) {
      mx = A.at(i);
      ans = i + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
