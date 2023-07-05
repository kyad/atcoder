#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long g(long long N) {
  if (N == 0) {
    return -1;
  }
  if (__builtin_popcountll(N) <= 2) {
    return g(N - 1);
  }
  long long ans = 0;
  int count = 0;
  for (int i = 63; i >= 0; i--) {
    if (N>>i&1LL) {
      ans |= (1LL<<i);
      count++;
      if (count == 3) {
        break;
      }
    }
  }
  assert(count == 3);
  assert(__builtin_popcountll(ans) == 3);
  return ans;
}

void testcase() {
  long long N;
  cin >> N;
  cout << g(N) << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
