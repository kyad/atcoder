#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<long long, long long> > C(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n).first >> C.at(n).second;
  }
  vector<pair<pair<long long, long long>, int> > D(N);
  for (int n = 0; n < N; n++) {
    D.at(n) = make_pair(C.at(n), n + 1);
  }
  
  sort(D.begin(), D.end(), [](const pair<pair<long long, long long>, int> &x, const pair<pair<long long, long long>, int> &y) {
    long long xa = x.first.first;
    long long xb = x.first.second;
    long long ya = y.first.first;
    long long yb = y.first.second;
    if (xa * (ya + yb) == ya * (xa + xb)) {
      int xi = x.second;
      int yi = y.second;
      return xi < yi;
    }
    return xa * (ya + yb) > ya * (xa + xb);
  });

  for (int n = 0; n < N; n++) {
    cout << D[n].second << " \n"[n == N - 1];
  }

  return 0;
}
