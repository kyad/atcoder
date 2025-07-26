#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N);
    set<long long> B;
    for (int i = 0; i < N; i++) {
      cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
      long long b;
      cin >> b;
      B.insert(b);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    long long ans = 0;
    for (int a: A) {
      auto it = B.lower_bound(M - a);
      long long b;
      if (it != B.end()) {  // 見つかった時
        b = *it;
        B.erase(it);
      } else {
        b = *B.begin();
        B.erase(B.begin());
      }
      long long now = (a + b) % M;
      ans += now;
    }
    cout << ans << '\n';
  }
  return 0;
}
