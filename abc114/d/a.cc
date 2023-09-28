#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

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
    while (N % m == 0) {
      N /= m;
      ans.push_back(m);
    }
  }
  if (N != 1) {
    ans.push_back(N);
  }
  return ans;
}

long long solve1(long long p) {
  return p;
}

long long solve2(long long a, long long b) {
  return a * b + a * (a - 1);
}
  
long long solve3(long long a, long long b) {
  return b * a * (a - 1) / 2 + a * (a - 1) * (a - 2) / 2;
}
  

int main() {
  int N;
  cin >> N;
  // mp[i]: N!を素因数分解したときの素因数iの個数
  map<int, int> mp;
  for (int n = 2; n <= N; n++) {
    for (int i : prime_factorization(n)) {
      mp[i]++;
    }
  }
  long long ans = 0;
  {
    // 1. P^74の形の時
    int p = 0;
    for (auto [i, count] : mp) {
      if (count >= 74) {
        p++;
      }
    }
    long long now = solve1(p);
    ans += now;
  }
  {
    // 2. P^14*Q^4の時
    int a = 0;
    int b = 0;
    for (auto [i, count] : mp) {
      if (count >= 4) {
        if (count >= 14) {
          a++;
        } else{
          b++;
        }
      }
    }
    long long now = solve2(a, b);
    ans += now;
  }
  {
    // 3. P^24*Q^2の時
    int a = 0;
    int b = 0;
    for (auto [i, count] : mp) {
      if (count >= 2) {
        if (count >= 24) {
          a++;
        } else{
          b++;
        }
      }
    }
    long long now = solve2(a, b);
    ans += now;
  }
  {
    // 4. P^2*Q^4*R^4の時
    int a = 0;
    int b = 0;
    for (auto [i, count] : mp) {
      if (count >= 2) {
        if (count >= 4) {
          a++;
        } else{
          b++;
        }
      }
    }
    long long now = solve3(a, b);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
