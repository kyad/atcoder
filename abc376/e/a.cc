#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N, K;
    cin >> N >> K;
    vector<pair<long long, long long> > AB(N);
    for (int i = 0; i < N; i++) {
      cin >> AB.at(i).first;
    }
    for (int i = 0; i < N; i++) {
      cin >> AB.at(i).second;
    }
    sort(AB.begin(), AB.end());
    long long mx = 0;  // Aの最大値
    multiset<long long, greater<long long> > smalls;  // Bのうち小さなK個
    long long sum = 0;  // smallsの合計
    for (int i = 0; i < K; i++) {
      auto [A, B] = AB.at(i);
      mx = A;
      smalls.insert(B);
      sum += B;
    }
    long long ans = mx * sum;
    for (int i = K; i < N; i++) {
      auto [A, B] = AB.at(i);
      mx = A;
      smalls.insert(B);
      sum += B;
      long long mv = *smalls.begin();
      smalls.erase(smalls.begin());
      sum -= mv;
      long long now = mx * sum;
      ans = min(ans, now);
    }
    cout << ans << '\n';
  }
  return 0;
}
