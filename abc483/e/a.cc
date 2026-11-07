#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  // ハミング距離がm
  auto f = [&](int m) {
    long long ans = 0;
    int r = M - m;  // r個取る
    // next_combination(N, r)
    vector<int> mask(M, 1);
    for (int j = 0; j < M - r; j++) {
      mask.at(j) = 0;
    }
    do {
      vector<string> T(N);
      for (int j = 0; j < M; j++) {
        if (mask.at(j)) {
          // Do something
          for (int i = 0; i < N; i++) {
            T.at(i).push_back(S.at(i).at(j));
          }
        }
      }
      // Tを処理する
      map<string, int> mp;
      for (int i = 0; i < N; i++) {
        mp[T.at(i)]++;
      }
      long long now = 0;
      for (auto [str, count]: mp) {
        now += comb2(count);
      }
      ans += now;
    } while (next_permutation(mask.begin(), mask.end()));
    return ans;
  };
  long long f0 = f(0);
  long long f1 = f(1);
  f1 -= M * f0;
  long long f2 = f(2);
  f2 -= (M - 1) * f1;
  f2 -= comb2(M) * f0;
  long long ans = f2 + f1 + f0;
  cout << ans << '\n';
  return 0;
}


