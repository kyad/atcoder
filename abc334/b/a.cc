#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  const long long C = 1000000000000000000LL;
  long long A, M, L, R;
  cin >> A >> M >> L >> R;
  A += C;
  L += C;
  R += C;
  assert(A >= 0LL);
  assert(L >= 0LL);
  assert(R >= 0LL);
  auto up = [&](long long x) -> long long {
    if (x >= A) {
      long long k = (x - A + M - 1) / M;
      long long ans = A + k * M;
      return ans;
    } else {
      long long k = (A - x) / M;
      long long ans = A - k * M;
      return ans;
    }
  };
  auto down = [&](long long x) -> long long {
    if (x >= A) {
      long long k = (x - A) / M;
      long long ans = A + k * M;
      return ans;
    } else {
      long long k = (A - x + M - 1) / M;
      long long ans = A - k * M;
      return ans;
    }
  };
  L = up(L);
  R = down(R);
  long long ans = 0;
  if (R < L) {
    ans = 0;
  } else {
    ans = (R - L) / M + 1;
  }
  cout << ans << endl;
  return 0;
}
