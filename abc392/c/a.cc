#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, -1);
  vector<int> B(N + 1, -1);
  vector<int> P(N + 1, -1);
  for (int i = 1; i <= N; i++) {
    cin >> P.at(i);
  }
  for (int i = 1; i <= N; i++) {
    int Q;
    cin >> Q;
    A.at(i) = Q;
    B.at(Q) = i;
  }
  for (int q = 1; q <= N; q++) {
    int i = B.at(q);
    int ii = P.at(i);
    int ans = A.at(ii);
    cout << ans << " \n"[q == N];
  }
  return 0;
}
