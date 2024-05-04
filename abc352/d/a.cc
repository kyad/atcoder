#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  vector<int> p2i(N, -1);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
    P.at(i)--;
    p2i.at(P.at(i)) = i;
  }
  set<int> is;
  for (int p = 0; p < K; p++) {
    int i = p2i.at(p);
    is.insert(i);
  }
  auto f = [&]() -> int {
    int mn = *is.begin();
    int mx = *is.rbegin();
    int ans = mx - mn;
    return ans;
  };
  int ans = f();
  for (int p = K; p < N; p++) {  // pを入れる、p-Kを出す
    is.erase(p2i.at(p - K));
    is.insert(p2i.at(p));
    int now = f();
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
