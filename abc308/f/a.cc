#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> P(N);
  multiset<long long> ms;
  long long sumP = 0;
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    ms.insert(P.at(n));
    sumP += P.at(n);
  }
  vector<long long> L(M);
  for (int m = 0; m < M; m++) {
    cin >> L.at(m);
  }
  vector<long long> D(M);
  for (int m = 0; m < M; m++) {
    cin >> D.at(m);
  }
  vector<pair<long long, long long> > A(M);
  for (int m = 0; m < M; m++) {
    A.at(m) = make_pair(D.at(m), L.at(m));
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  long long sumd = 0;
  for (int m = 0; m < M; m++) {
    long long d = A[m].first;
    long long l = A[m].second;
    multiset<long long>::iterator it = ms.lower_bound(l);
    if (it == ms.end()) {
      continue;
    }
    sumd += d;
    ms.erase(it);
  }
  long long ans = sumP - sumd;
  cout << ans << endl;
  return 0;
}
