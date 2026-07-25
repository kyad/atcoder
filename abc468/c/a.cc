#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  vector<int> Q(N);
  for (int i = 0; i < N; i++) {
    cin >> Q.at(i);
  }
  // 順列初期化
  vector<int> A(N, -1);
  for (int i = 0; i < N; i++) {
    A.at(i) = i + 1;
  }
  // 順列全探索
  int ans = 0;
  do {
    if (P < A && A < Q) {
      ans++;
    }
  } while (next_permutation(A.begin(), A.end()));
  cout << ans << '\n';
  return 0;
}
