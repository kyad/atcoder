#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<long long, long long> > AB(N);
  set<long long> ts;
  for (int n = 0; n < N; n++) {
    long long T, D;
    cin >> T >> D;
    long long A = T;
    long long B = T + D;
    AB.at(n) = make_pair(A, B);
    ts.insert(A);
    ts.insert(B);
  }
  sort(AB.begin(), AB.end());

  multiset<pair<long long, long long> > ms;  // (B, A)で管理する
  int n = 0;  // 次に入れるもの
  int ans = 0;
  for (set<long long>::iterator it = ts.begin(); it != ts.end(); it++) {
    long long t = *it;
    // 時刻tで始まるものを追加
    while (n < N) {
      auto [a, b] = AB.at(n);
      if (t == a) {
        ms.insert(make_pair(b, a));
        n++;
      } else {
        break;
      }
    }
    // 印刷
    if (!ms.empty()) {
      auto [b, a] = *ms.begin();
      if (a <= t && t <= b) {
        ans++;
        ms.erase(ms.begin());
      }
    }
    // 削除
    while (!ms.empty()) {
      auto [b, a] = *ms.begin();
      if (b <= t) {
        ms.erase(ms.begin());
      } else {
        break;
      }
    }
    // 今のtから、次のnt-1までに消せるやつは今印刷してしまう
    set<long long>::iterator nit = next(it);
    if (nit != ts.end()) {
      long long nt = *nit;
      long long tt = t + 1;
      while (!ms.empty()) {
        if (tt >= nt) {
          break;
        }
        auto [b, a] = *ms.begin();
        if (a <= tt && tt <= b) {
          ans++;
          ms.erase(ms.begin());
          tt++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
