// https://atcoder.jp/contests/abc239/tasks/abc239_d

#include <iostream>
#include <vector>
using namespace std;

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

// Sieve of Eratosthenes  O(N * sqrt(N))
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
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  vector<bool> is_prime = eratosthenes(200);
  string ans = "Aoki";
  for (int t = A; t <= B; t++) { // 100
    bool ok = true;
    for (int a = C; a <= D; a++) { // 100
      int temp = t + a;
      if (is_prime[temp]) {
        ok = false;
      }
    }
    if (ok) {
      ans = "Takahashi";
    }
  }
  cout << ans << endl;
  return 0;
}
