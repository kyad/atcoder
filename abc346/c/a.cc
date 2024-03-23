#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  long long ans = K * (K + 1) / 2;
  set<long long> used;
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    if (A > K) {
      continue;
    }
    if (used.contains(A)) {
      continue;
    }
    used.insert(A);
    ans -= A;
  }
  cout << ans << endl;
  return 0;
}
