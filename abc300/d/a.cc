#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// int(sqrt(n)) for 0 <= n <= 10^18 (答えがintの範囲で収まる場合に動作する)
// 計算量 O(log(RIGHT_MAX))
int int_sqrt(long long n) {
  if (n == 0) {
    return 0;
  }    
  int left = 0;
  const int RIGHT_MAX = 1e9+1;  // >= sqrt(max(n)). 2乗してlong longの範囲に収まること
  int right = RIGHT_MAX;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    long long y = (long long)mid * mid - n;
    if (y <= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

#if 0
// int(sqrt(N))  O(log(N))
int int_sqrt(int N) {
  int left = 0;
  int right = N;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (middle * middle >= N) {
      right = middle;
    } else {
      left = middle;
    }
  }
  if (right * right >= N) {
    return right;
  } else {
    return left;
  }
}
#endif

// Sieve of Eratosthenes  O(N * log log (N))
vector<bool> eratosthenes(int N) {
  vector<bool> is_prime(N + 1, true);
  is_prime.at(0) = false;
  if (N > 0) {
    is_prime.at(1) = false;
  }
  for (int k = 2; k < int_sqrt(N); k++) {
    for (int i = 2 * k; i <= N; i+=k) {
      is_prime.at(i) = false;
    }
  }
  return is_prime;
}

int main() {
  long long N;
  cin >> N;
  vector<bool> is_prime = eratosthenes(1000010);
  vector<long long> primes, neg_primes;
  for (int i = 2; i < 1000010; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      neg_primes.push_back(-i);
    }
  }
  reverse(neg_primes.begin(), neg_primes.end());
  long long ans = 0;
  for (long long a = 2; a <= 252; a++) {
    if (!is_prime[a]) {
      continue;
    }
    long long bmax = N / a;
    for (long long b = a + 1; b * b * b <= bmax; b++) {
      if (!is_prime[b]) {
        continue;
      }
      long long cmin = b + 1;
      long long cmax = int_sqrt(N / (a * a * b));
      if (cmin >= cmax) {
        continue;
      }
      auto lit = lower_bound(primes.begin(), primes.end(), cmin);
      long long l = lit - primes.begin();
      auto rit = lower_bound(neg_primes.begin(), neg_primes.end(), -cmax);
      long long r = neg_primes.end() - rit;
      long long now = r - l;
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
