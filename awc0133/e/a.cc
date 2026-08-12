#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, K, T;
  cin >> N >> M >> K >> T;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int now = 0;
    vector<int> S(M);
    for (int j = 0; j < M; j++) {
      cin >> S.at(j);
    }
    multiset<int> ms;
    // 最初
    for (int j = 0; j < K; j++) {
      ms.insert(S.at(j));
    }
    int diff = *ms.rbegin() - *ms.begin();
    if (diff >= T) {
      now = 1;
    }
    for (int j = 1; j <= M - K; j++) {
      ms.erase(ms.find(S.at(j - 1)));
      ms.insert(S.at(j + K - 1));
      int diff = *ms.rbegin() - *ms.begin();
      if (diff >= T) {
        now = 1;
      }
    }
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
