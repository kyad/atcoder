#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  vector<int> C(N);
  vector<vector<bool> > F(N, vector<bool>(M, false));
  for (int n = 0; n < N; n++) {
    cin >> P.at(n) >> C.at(n);
    for (int c = 0; c < C.at(n); c++) {
      int f;
      cin >> f;
      f--;
      F.at(n).at(f) = true;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      // 1
      if (P[i] < P[j]) {
        continue;
      }
      // 2
      bool ok = true;
      for (int m = 0; m < M; m++) {
        if (F[i][m] == true && F[j][m] == false) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      // 3
      if (P[i] > P[j] || C[i] < C[j]) {
        //cerr << "i=" << i << " j=" << j << endl;
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
