#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
  }
  vector<int> prev(M, 0), next(M, 0);
  for (int i = 0; i < N; i++) {
    prev.at(A.at(i))++;
    next.at(B.at(i))++;
  }
  for (int j = 0; j < M; j++) {
    int ans = next.at(j) - prev.at(j);
    cout << ans << '\n';
  }
  return 0;
}
