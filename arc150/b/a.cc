// https://atcoder.jp/contests/arc150/tasks/arc150_b

#include <iostream>
#include <vector>
using namespace std;

// int(sqrt(n)) for 0 <= n <= INT_MAX
int int_sqrt(int n) {
  if (n == 0) {
    return 0;
  }    
  int left = 0;
  int right = 1e5; // <= sqrt(INT_MAX)
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

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int testcase(int A, int B) {
  if (A >= B) {
    return A - B;
  }
  int ans = 2e9+2;
  
  for (int k = A; k <= int_sqrt(2 * max(A, B)) + 2; k++) {
    int X = k - A;
    int r = B % k;
    int Y = r > 0 ? k - r : 0;
    ans = min(ans, X + Y);
  }
  for (int k = 1; k <= int_sqrt(2 * max(A, B)) + 2; k++) {
    int X;
    if (B > (long long)k * A) {
      X = ceildiv(B, k) - A;
    } else {
      X = 0;
    }
    long long Y = (long long) (A + X) * k - B;
    ans = min((long long)ans, Y + X);
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int A, B;
    cin >> A >> B;
    long long ans = testcase(A, B);
    cout << ans << endl;
  }
  return 0;
}
