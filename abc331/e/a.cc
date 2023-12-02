#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, L;
  cin >> N >> M >> L;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  vector<set<int> > ngs(N);
  for (int l = 0; l < L; l++) {
    int C, D;
    cin >> C >> D;
    C--; D--;
    ngs.at(C).insert(D);
  }
  vector<pair<long long, int> > C(M);  // (-値段, 副菜番号m)
  for (int m = 0; m < M; m++) {
    C.at(m) = make_pair(-B.at(m), m);
  }
  sort(C.begin(), C.end());

  const long long INF = 4e18;
  long long ans = -INF;
  for (int n = 0; n < N; n++) {  // Aを固定
    long long now = -INF;
    for (int m = 0; m < M; m++) {
      long long cost = -C.at(m).first;
      int id = C.at(m).second;
      if (ngs.at(n).contains(id)) {
        continue;
      }
      now = A.at(n) + cost;
      break;
    }
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
