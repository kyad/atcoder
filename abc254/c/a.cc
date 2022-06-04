#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a;
    B[i] = a;
  }
  sort(B.begin(), B.end());
  map<int, multiset<int> > sa, sb;
  for (int i = 0; i < N; i++) {
    sa[A[i]].insert(i % K);
    sb[B[i]].insert(i % K);
  }
  bool ok = true;
  for (map<int, multiset<int> >::iterator it = sa.begin(); it != sa.end(); it++) {
    int a = it->first;
    if (it->second != sb[a]) {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
