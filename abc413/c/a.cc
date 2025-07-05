#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  queue<pair<long long, long long> > q;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      long long C, X;
      cin >> C >> X;
      q.push(make_pair(C, X));
    } else {
      long long K;
      cin >> K;
      long long sum = 0;
      while (K > 0) {
        auto [c, x] = q.front();
        long long take = min(K, c);
        K -= take;
        sum += take * x;
        if (take == c) {
          q.pop();
        } else {
          q.front().first -= take;
        }
      }
      cout << sum << '\n';
    }
  }
  return 0;
}
