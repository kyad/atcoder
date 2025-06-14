#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> L(M), R(M);
  for (int j = 0; j < M; j++) {
    cin >> L.at(j) >> R.at(j);
    L.at(j)--;
    R.at(j)--;
  }
  vector<int> A(N + 1, 0);
  for (int j = 0; j < M; j++) {
    A.at(L.at(j))++;
    A.at(R.at(j) + 1)--;
  }
  // imos
  for (int i = 0; i < N; i++) {
    A.at(i + 1) += A.at(i);
  }
  const int INF = 1e9;
  int ans = INF;
  for (int i = 0; i < N; i++) {
    ans = min(ans, A.at(i));
  }
  cout << ans << endl;
  return 0;
}
