// https://www.youtube.com/watch?v=T_ptI5WGA0w&t=4224s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  long long N, X, K;
  cin >> N >> X >> K;
  auto f = [&](long long v, long long d) -> long long {
    long long l = v;
    for (int i = 0; i < d; i++) {
      l *= 2;
      if (l > N) {
        return 0;
      }
    }
    long long r = l + (1LL<<d) - 1;
    r =  min(r, N);
    long long ans = r - l + 1;
    return ans;    
  };
  long long ans = f(X, K);
  while (X >= 2 && K >= 2) {
    ans += f(X ^ 1, K - 2);
    X /= 2;
    K--;
  }
  if (X >= 2 && K == 1) {
    ans++;
  }
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
