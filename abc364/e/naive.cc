#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  vector<int> P(N, -1);
  for (int i = 0; i < N; i++) {
    P.at(i) = i;
  }
  int ans = 0;
  do {
    int now = 0;
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < N; i++) {
      int p = P.at(i);
      now++;
      sumA += A.at(p);
      sumB += B.at(p);
      if (sumA > X || sumB > Y) {
        break;
      }
    }
    ans = max(ans, now);
  } while (next_permutation(P.begin(), P.end()));
  cout << ans << endl;
  return 0;
}
