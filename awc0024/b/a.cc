#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<bool> dp(N, false);
  for (int i = 0; i < K; i++) {
    dp.at(i) = true;
  }
  for (int j = 0; j < M; j++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    if (dp.at(A)) {
      dp.at(B) = true;
    } else if (dp.at(B)) {
      dp.at(A) = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (dp.at(i)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
