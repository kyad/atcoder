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
  vector<int> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  long long a = *max_element(A.begin(), A.end());
  long long b = *max_element(B.begin(), B.end());
  long long ans = a + b;
  cout << ans << endl;
  return 0;
}
