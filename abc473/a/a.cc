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
  for (int i = N / 2; i < N; i++) {
    ans += A.at(i);
  }
  cout << ans << '\n';
  return 0;
}
