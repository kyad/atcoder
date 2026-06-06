#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K, M;
  cin >> N >> K >> M;
  vector<int> C(N);
  vector<long long> V(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i) >> V.at(i);
    C.at(i)--;
  }
  vector<tuple<long long, int, int> > VC(N);
  for (int i = 0; i < N; i++) {
    VC.at(i) = make_tuple(V.at(i), C.at(i), i);
  }
  sort(VC.begin(), VC.end());
  reverse(VC.begin(), VC.end());
  // used_c[c]: Whether color c is used
  vector<bool> used_c(N, false);
  // used[i]: Whether jewel i is used
  vector<bool> used(N, false);
  long long ans = 0;
  int count1 = 0;
  for (auto [v, c, i]: VC) {
    if (count1 >= M) {
      break;
    }
    if (used_c.at(c)) {
      continue;
    }
    ans += v;
    used.at(i) = true;
    used_c.at(c) = true;
    count1++;
  }
  int count2 = 0;
  for (auto [v, c, i]: VC) {
    if (count2 >= K - M) {
      break;
    }
    if (used.at(i)) {
      continue;
    }
    ans += v;
    used.at(i) = true;
    count2++;
  }
  cout << ans << '\n';
  return 0;
}
