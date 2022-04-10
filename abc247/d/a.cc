#include <iostream>
#include <queue>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  deque<pair<int, int> > que;
  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int x, c;
      cin >> x >> c;
      que.push_back(make_pair(x, c));
    } else {
      int cq;
      cin >> cq;
      long long ans = 0;
      while (!que.empty()) {
        int xs = que.front().first;
        int cs = que.front().second;
        int get = min(cs, cq);
        if (get == 0) {
          break;
        }
        ans += (long long) get * (long long) xs;
        que.pop_front();
        if (get != cs) {
          que.push_front(make_pair(xs, cs - get));
        }
        cq -= get;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
