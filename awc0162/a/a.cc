#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  vector<int> count(N, 0);
  for (int j = 0; j < M; j++) {
    int T, P;
    cin >> T >> P;
    T--;
    if (S.at(T) - count.at(T) >= P) {
      count.at(T) += P;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (count.at(i) == S.at(i)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
