#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> C(M);
  for (int j = 0; j < M; j++) {
    cin >> C.at(j);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int A;
    long long B;
    cin >> A >> B;
    A--;
    long long now = min(B, C.at(A));
    C.at(A) -= now;
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
