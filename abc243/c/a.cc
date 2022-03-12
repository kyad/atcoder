#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  vector<int> Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  string S;
  cin >> S;
  map<int, int> Rmin;
  map<int, int> Lmax;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'R') {
      if (Rmin.count(Y[n]) == 0) {
        Rmin[Y[n]] = X[n];
      } else {
        Rmin[Y[n]] = min(Rmin[Y[n]], X[n]);
      }
    } else {
      if (Lmax.count(Y[n]) == 0) {
        Lmax[Y[n]] = X[n];
      } else {
        Lmax[Y[n]] = max(Lmax[Y[n]], X[n]);
      }
    }
  }
  bool ans = false;
  for (map<int, int>::iterator it = Rmin.begin(); it != Rmin.end(); it++) {
    int y = it->first;
    int rmin = it->second;
    if (Lmax.count(y) == 0) {
      continue;
    }
    if (rmin < Lmax[y]) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
