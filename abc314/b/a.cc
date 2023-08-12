#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<set<int> > st(37);
  vector<int> sz(N, 0);
  for (int n = 0; n < N; n++) {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
      int A;
      cin >> A;
      st.at(A).insert(n);
      sz[n]++;
    }
  }
  int X;
  cin >> X;
  vector<pair<int, int> > P;
  for (int n : st.at(X)) {
    P.push_back(make_pair(sz[n], n));
  }
  sort(P.begin(), P.end());
  int L = P.size();
  if (L == 0) {
    cout << L << endl;
    cout << endl;
    return 0;
  }
  int sz0 = P[0].first;
  vector<int> B;
  for (int k = 0; k < L; k++) {
    if (P[k].first == sz0) {
      B.push_back(P[k].second + 1);
    }
  }
  int K = B.size();
  sort(B.begin(), B.end());
  cout << K << endl;
  for (int k = 0; k < K; k++) {
    cout << B.at(k);
    if (k < K - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }
  return 0;
}
