#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> count(M, 0);
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int k = 0; k < K; k++) {
      int C;
      cin >> C;
      C--;
      count.at(C)++;
    }
  }
  int ans = 0;
  for (int j = 0; j < M; j++) {
    if (count.at(j) == N) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
