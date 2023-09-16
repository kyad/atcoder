#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  multiset<tuple<int, int, int, int> > events;
  for (int m = 0; m < M; m++) {
    int T, W, S;
    cin >> T >> W >> S;
    events.insert(make_tuple(T, 1, W, S));
  }
  vector<long long> ans(N, 0);
  set<int> person;
  for (int n = 0; n < N; n++) {
    person.insert(n);
  }
  while (!events.empty()) {
    int t = get<0>(*events.begin());
    int type = get<1>(*events.begin());
    if (type == 0) {
      // 人が戻る
      int p = get<2>(*events.begin());
      person.insert(p);
    } else {
      long long w = get<2>(*events.begin());
      int s = get<3>(*events.begin());
      if (!person.empty()) {
        int p = *person.begin();
        ans[p] += w;
        events.insert(make_tuple(t + s, 0, p, -1));
        person.erase(p);
      }
    }
    events.erase(events.begin());
  }
  for (int n = 0; n < N; n++) {
    cout << ans[n] << '\n';
  }
  return 0;
}
