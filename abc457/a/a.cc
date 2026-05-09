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
  int X;
  cin >> X;
  int ans = A.at(X - 1);
  cout << ans << '\n';
  return 0;
}
