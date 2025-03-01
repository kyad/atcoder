#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  const int M = 1000000;
  vector<vector<int> > is(M + 1);
  for (int i = 0; i < N; i++) {
    is.at(A.at(i)).push_back(i);
  }
  const int INF = 1e9;
  int ans = INF;
  for (int m = 1; m <= M; m++) {
    int K = is.at(m).size();
    for (int k = 1; k < K; k++) {
      int now = is.at(m).at(k) - is.at(m).at(k - 1) + 1;
      ans = min(ans, now);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
