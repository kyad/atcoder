#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > AB(M), CD(M);
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    AB.at(m).first = min(a, b);
    AB.at(m).second = max(a, b);
  }
  for (int m = 0; m < M; m++) {
    int c, d;
    cin >> c >> d;
    c--;
    d--;
    CD.at(m).first = min(c, d);
    CD.at(m).second = max(c, d);
  }
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    P.at(n) = n;
  }
  bool ans = false;
  do {
    bool ok0 = true;
    for (int m = 0; m < M; m++) {
      int i = AB.at(m).first;
      int j = AB.at(m).second;
      int pi = min(P.at(i), P.at(j));
      int pj = max(P.at(i), P.at(j));
      bool ok1 = false;
      for (int m1 = 0; m1 < M; m1++) {
        if (CD.at(m1).first == pi && CD.at(m1).second == pj) {
          ok1 = true;
        }
      }
      if (!ok1) {
        ok0 = false;
      }
    }
    if (ok0) {
      ans = true;
    }
  } while (next_permutation(P.begin(), P.end()));
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
