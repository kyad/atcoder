#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N;
  cin >> N;
  vector<long long> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
  }
  // 平行四辺形を重複して数えた台形の個数
  map<pair<long long, long long>, int> mp1;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      long long dx = X.at(j) - X.at(i);
      long long dy = Y.at(j) - Y.at(i);
      if (dx < 0) {
        dx *= -1;
        dy *= -1;
      }
      if (dx == 0) {
        dy = 1;
      } else if (dy == 0) {
        dx = 1;
      } else {
        long long g = __gcd(abs(dx), abs(dy));
        dx /= g;
        dy /= g;
      }
      mp1[make_pair(dx, dy)]++;
    }
  }
  long long sum1 = 0;
  for (auto [key, count]: mp1) {
    sum1 += comb2(count);
  }
  // 平行四辺形の個数
  map<pair<long long, long long>, int> mp2;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      long long cx = X.at(i) + X.at(j);
      long long cy = Y.at(i) + Y.at(j);
      mp2[make_pair(cx, cy)]++;
    }
  }
  long long sum2 = 0;
  for (auto [key, count]: mp2) {
    sum2 += comb2(count);
  }
  long long ans = sum1 - sum2;
  cout << ans << endl;
  return 0;
}
