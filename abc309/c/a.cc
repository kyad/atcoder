#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<pair<int, long long> > AB(N);
  long long sum = 0;
  for (int n = 0; n < N; n++) {
    int a;
    long long b;
    cin >> a >> b;
    sum += b;
    AB.at(n) = make_pair(a, b);
  }
  sort(AB.begin(), AB.end());
  if (sum <= K) {
    cout << 1 << endl;
    return 0;
  }
  for (auto [a, b] : AB) {
    sum -= b;
    if (sum <= K) {
      cout << a + 1 << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
