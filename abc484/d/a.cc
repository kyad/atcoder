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
  vector<int> count(N + 1, 0);
  long long ans = 1;
  count.at(A.at(0))++;
  for (int i = 1; i < N; i++) {
    if (A.at(i) != A.at(i - 1)) {
      long long now = i - count.at(A.at(i));
      ans += now;
    }
    count.at(A.at(i))++;
  }
  cout << ans << '\n';
  return 0;
}
