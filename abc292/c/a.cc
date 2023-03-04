#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// int(sqrt(n)) for n >= 0
int int_sqrt(int n) {
  if (n == 0) {
    return 0;
  }    
  int left = 0;
  int right = 200001;
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

int main() {
  int N;
  cin >> N;
  vector<long long> count(N, 0);
  for (int x = 1; x <= N - 1; x++) {
    int R = int_sqrt(x);
    for (int p = 1; p <= R; p++) {
      int q = x / p;
      if (p * q == x) {
        if (p == q) {
          count[x]++;
        } else {
          count[x] += 2;
        }
      }
    }
  }
  long long ans = 0;
  for (int x = 1; x <= N - 1; x++) {
    ans += count[x] * count[N - x];
  }
  cout << ans << endl;
  return 0;
}
