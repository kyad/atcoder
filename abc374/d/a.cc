#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const long long INF = 4e18;

double dist(double x0, double y0, double x1, double y1) {
  return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main() {
  int N, S, T;
  cin >> N >> S >> T;
  vector<int> A(N), B(N), C(N), D(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);
  }
  vector<int> P(N, -1);
  for (int i = 0; i < N; i++) {
    P.at(i) = i;
  }
  double ans = INF;
  int N2 = 1<<N;
  do {
    for (int bit = 0; bit < N2; bit++) {  // 0=Pが先, 1=Qが先
      vector<int> xs, ys;
      xs.push_back(0);
      ys.push_back(0);
      for (int i = 0; i < N; i++) {  // 0, ..., Nの並べ方
        int p = P.at(i);  //
        if (bit>>i&1) {  // Qが先
          xs.push_back(C.at(p));
          ys.push_back(D.at(p));
          xs.push_back(A.at(p));
          ys.push_back(B.at(p));
        } else {  // Pが先
          xs.push_back(A.at(p));
          ys.push_back(B.at(p));
          xs.push_back(C.at(p));
          ys.push_back(D.at(p));
        }
      }
      // 秒数を求める
      assert((int)(xs.size()) == N * 2 + 1);
      double now = 0;
      for (int i = 0; i < N * 2; i++) {
        double v;
        if (i % 2 == 0) {
          v = S;
        } else {
          v = T;
        }
        double d = dist(xs.at(i), ys.at(i), xs.at(i + 1), ys.at(i + 1));
        double t = d / v;
        now += t;
      }
      ans = min(ans, now);
    }
  } while (next_permutation(P.begin(), P.end()));
  cout << setprecision(15) << ans << endl;
  return 0;
}
