#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<pair<int, int> > S(K);
  for (int k = 0; k < K; k++) {
    int A;
    cin >> A;
    S.at(k) = make_pair(A, k + 1);
  }
  for (int q = 0; q < Q; q++) {
    int L;
    cin >> L;
    L--;
    sort(S.begin(), S.end());
    if (L == K - 1) {
      int p0 = S[L].first;
      if (p0 >= N) {
        continue;
      }
    } else {
      int p0 = S[L].first;
      int p1 = S[L + 1].first;
      if (p0 + 1 >= p1) {
        continue;
      }
    }
    S[L].first++;
  }
  sort(S.begin(), S.end());
  for (int k = 0; k < K; k++) {
    cout << S[k].first << (k == K - 1 ? '\n' : ' ');
  }
  return 0;
}
