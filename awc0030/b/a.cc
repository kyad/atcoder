#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> P(N);
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i) >> T.at(i);
  }
  const long long INF = 4e18;
  for (int j = 0; j < M; j++) {
    int K;
    cin >> K;
    long long min0 = INF;
    long long min1 = INF;
    for (int k = 0; k < K; k++){
      int S;
      cin >> S;
      S--;
      if (T.at(S) == 0) {
        min0 = min(min0, P.at(S));
      } else {
        min1 = min(min1, P.at(S));
      }
    }
    long long ans = -1;
    if (min0 != INF && min1 != INF) {
      ans = min0 + min1;
    }
    cout << ans << '\n';
  }
  return 0;
}
