#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> X(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n);
  }
  vector<pair<double, long long> > Y(N);
  for (int n = 0; n < N; n++) {
    Y.at(n) = make_pair(1. / X[n], X[n]);
  }
  sort(Y.begin(), Y.end());
  const double INF = 1e18+2;
  double mn = INF;
  double mx = -INF;
  vector<long long> Z;
  if (N <= 6) {
    for (int n = 0; n < N; n++) {
      Z.push_back(Y[n].second);
    }
  } else {
    for (int i = 0; i < 3; i++) {
      Z.push_back(Y[i].second);
    }
    for (int i = 0; i < 3; i++) {
      Z.push_back(Y[N - 3 + i].second);
    }
  }
  int M = Z.size();
  
  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      for (int k = j + 1; k < M; k++) {
        double now = (double)(Z[i] + Z[j] + Z[k]) / (double)(Z[i] * Z[j] * Z[k]);
        mn = min(mn, now);
        mx = max(mx, now);
      }
    }
  }
  cout << setprecision(15) << mn << endl;
  cout << setprecision(15) << mx << endl;
  return 0;
}
