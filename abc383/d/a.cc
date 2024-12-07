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
  vector<bool> is_prime = eratosthenes(2000001);

  // a * a * b * bの時 (a<b)
  int ans0 = 0;
  for (long long a = 2; a * a * a * a <= N; a++) {
    if (!is_prime[a]) {
      continue;
    }
    long long U = N / a / a;
    for (long long b = a + 1; b * b <= U; b++) {
      if (!is_prime[b]) {
        continue;
      }
      if (a * a * b * b <= N) {
        ans0++;
      }
    }
  }

  // a ^ 8の時
  int ans1 = 0;
  for (long long a = 2; a * a * a * a * a * a * a * a <= N; a++) {
    if (!is_prime[a]) {
      continue;
    }
    ans1++;
  }

  int ans = ans0 + ans1;
  cout << ans << endl;
  return 0;
}
