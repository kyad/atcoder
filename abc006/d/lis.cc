// https://atcoder.jp/contests/abc006/tasks/abc006_4

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> c(N);
  for (int n = 0; n < N; n++) {
    cin >> c.at(n);
  }
  // LIS
  const int INF = 30001;
  size_t len = 1;
  vector<int> L(N + 1, INF);
  L.at(0) = 0;
  for (int n = 0; n < N; n++) {
    vector<int>::iterator it = lower_bound(L.begin(), L.end(), c.at(n));
    size_t pos = distance(L.begin(), it);
    len = max(len, pos);
    *it = c.at(n);
  }
  cout << N - len << endl;
  return 0;
}

