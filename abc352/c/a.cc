#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N), B(N), H(N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    H.at(i) = B.at(i) - A.at(i);
    ans += A.at(i);
  }
  long long h = *max_element(H.begin(), H.end());
  ans += h;
  cout << ans << endl;
  return 0;
}
