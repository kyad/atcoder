#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  // Aから単調減少になるように取る
  vector<int> C;
  map<int, int> mp;
  const int INF = 1e9;
  int amax = INF;
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    if (a < amax) {
      C.push_back(a);
      mp[a] = i;
      amax = a;
    }
  }
  sort(C.begin(), C.end());
  for (int b : B) {
    vector<int>::iterator it = upper_bound(C.begin(), C.end(), b);
    int ans;
    if (it == C.begin()) {
      ans = -1;
    } else {
      int a = *prev(it);  // 食べる人の美食度
      ans = mp[a] + 1;  // idxに直す
    }
    cout << ans << '\n';
  }
  return 0;
}
