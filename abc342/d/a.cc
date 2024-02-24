#include <algorithm>
#include <cassert>
#include <cmath>
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

vector<int> f(int N) {
  map<int, int> mp;
  for (int p: prime_factorization(N)) {
    mp[p]++;
  }
  vector<int> ans;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int value = it->first;
    int count = it->second;
    count %= 2;
    if (count == 0) {
      continue;
    }
    ans.push_back(value);
  }
  return ans;
}

long long comb2(long long N) { return N * (N - 1) / 2; }

int solve(int N, vector<int> &A) {
  map<vector<int>, int> mp;
  long long zeros = 0;
  for (int i = 0; i < N; i++) {
    int a = A[i];
    if (a == 0) {
      zeros++;
    } else {
      mp[f(a)]++;
    }
  }
  long long ans = zeros * (N - 1) - comb2(zeros);
  for (auto it = mp.begin(); it != mp.end(); it++) {
    long long count = it->second;
    ans += comb2(count);
  }
  cout << ans << endl;
  return 0;
}

int naive(int N, vector<int> &A) {
  auto g = [&](long long a, long long b) {
    long long c = a * b;
    long long r = sqrt(c);
    if ((r - 1) * (r - 1) == c) {
      return true;
    }
    if (r * r == c) {
      return true;
    }
    if ((r + 1) * (r + 1) == c) {
      return true;
    }
    return false;
  };
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (g(A[i], A[j]) ) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  solve(N, A);
  return 0;
}
