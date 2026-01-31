#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  priority_queue<pair<int, bool>, vector<pair<int, bool> >, greater<pair<int, bool> > > pq;
  pq.push(make_pair(0, true));
  for (int i = 0; i < N; i++) {
    pq.push(make_pair(A.at(i), false));
  }
  pq.push(make_pair(T, false));

  bool open = true;
  long long ans = 0;
  while (!pq.empty()) {
    auto [t, next] = pq.top();
    if (t >= T) {
      break;
    }
    pq.pop();
    auto [nt, _] = pq.top();
    if (next == true) {
      open = true;
    } else {
      if (open == true) {
        pq.push(make_pair(t + 100, true));
      }
      open = false;
    }
    if (open == true) {
      ans += (nt - t);
    }
  }

  cout << ans << '\n';
  return 0;
}
