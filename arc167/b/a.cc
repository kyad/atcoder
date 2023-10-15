#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

/**
 * 素因数分解して結果を重複も込めて小さい順に返す。
 * 計算量: O(sqrt(N))
 * 制約: Tはint, unsigned int, long long, unsigned long longのいずれか
 * \param N 素因数分解する数
 * \return vector<T> 素因数の配列。重複も込める。小さい順。1は含めない
 */
template<typename T> vector<T> prime_factorization(T N) {
  vector<T> ans;
  for (long long m = 2; m * m <= (long long)N; m++) {  // Care for overflow
    while (N % m == 0){ 
      N /= m;
      ans.push_back(m);
    }
  }
  if (N != 1) {
    ans.push_back(N);
  }
  return ans;
}

int main() {
  long long A, B;
  cin >> A >> B;
  bool Bodd = (B % 2 == 1);
  vector<long long> ps = prime_factorization(A);
  map<long long, int> mp;
  for (long long p : ps) {
    mp[p]++;
  }
  mint X = 1;
  bool Xodd = true;
  for (auto [prime, p]: mp) {
    mint now = p;
    now *= B;
    now += 1;
    X *= now;
    if (p % 2 == 1 && B % 2 == 1) {
      Xodd = false;
    }
  }
  mint ans;
  if (Bodd && Xodd) {
    ans = (X * B - 1) / 2;
  } else {
    ans = X * B / 2;
  }
  cout << ans << endl;
  return 0;
}
