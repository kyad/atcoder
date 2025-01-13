#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  sort(B.begin(), B.end());
  int i = 0;
  long long ans = 0;
  for (int j = 0; j < M; j++) {
    while (true) {
      if (i >= N) {
        cout << -1 << endl;
        return 0;
      }
      if (A.at(i) >= B.at(j)) {
        ans += A.at(i);
        i++;
        break;
      } else {
        i++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
