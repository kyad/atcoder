#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans -= A[i];
  }
  cout << ans << endl;
  return 0;
}
