#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long X;
  cin >> N >> K >> X;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  vector<pair<int, bool> > B(N);
  for (int i = 0; i < N; i++) {
    B.at(i).first = A.at(i);
    if (i < K) {
      B.at(i).second = true;
    } else {
      B.at(i).second = false;
    }
  }
  int ans = -1;
  int drink = 0;
  long long sake = 0;
  for (int i = N - 1; i >= 0; i--) {
    drink++;
    if (B.at(i).second) {
      sake += B.at(i).first;
    }
    if (sake >= X) {
      ans = drink;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
