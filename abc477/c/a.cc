#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  string S;
  cin >> S;
  int N = S.size();
  S.insert(S.begin(), '_');
  string T;
  cin >> T;
  int M = T.size();
  vector<int> U(N + 1, 0);
  for (int i = 1; i <= N - M + 1; i++) {
    bool ok = true;
    for (int k = 0; k < M; k++) {
      if (S.at(i + k) != T.at(k)) {
        ok = false;
      }
    }
    if (ok) {
      U.at(i) = 1;
    }
  }
  vector<int> V(U); // N+1
  for (int i = 1; i <= N; i++) {
    V.at(i) += V.at(i - 1);
  }
  
  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    cin >> L >> R;
    int l = L;
    int r = R - M + 1;
    bool ans;
    if (r < l) {
      ans = false;
    } else {
      int diff = V.at(r) - V.at(l - 1);
      if (diff >= 1) {
        ans = true;
      } else {
        ans = false;
      }
    }
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
