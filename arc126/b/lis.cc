// https://atcoder.jp/contests/arc126/tasks/arc126_b
// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > ab(M);
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    ab.at(m) = make_pair(a, -b);
  }
  sort(ab.begin(), ab.end());
  vector<int> b(M);
  for (int m = 0; m < M; m++) {
    b.at(m) = -ab.at(m).second;
  }
  // LIS
  // L[m] is the minimum value is m-th value of LIS
  const int INF = 200001;
  vector<int> L(M + 1, INF);
  L.at(0) = -1;
  int len = 0;
  for (int m = 0; m < M; m++) {
    int x = b.at(m);
    vector<int>::iterator it = lower_bound(L.begin(), L.end(), x);
    len = max(len, (int)distance(L.begin(), it));
    *it = x;
  }
  cout << len << endl;
  return 0;
}
