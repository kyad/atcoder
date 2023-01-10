#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <atcoder/string>
using namespace atcoder;

int main() {
  int N;
  cin >> N;
  string T;
  cin >> T;
  string u = T.substr(0, N);
  string v = T.substr(N, N * 2);
  string ru(u);
  reverse(ru.begin(), ru.end());
  string rv(v);
  reverse(rv.begin(), rv.end());
  string a = u + rv;
  string b = ru + v;
  vector<int> za = z_algorithm(a);
  vector<int> zb = z_algorithm(b);
  for (int i = 0; i < N; i++) {
    if (i > 0 && za[2 * N - i] != i) {
      continue;
    }
    int j = N - i;
    if (zb[2 * N - j] != j) {
      continue;
    }
    string S = a.substr(0, i) + b.substr(0, j);
    cout << S << endl;
    cout << i << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
