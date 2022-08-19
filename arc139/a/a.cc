#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// aより大きく、末尾に0がk個以上続く最小の数を返す
static long long next1(long long a, int k) {
  long long ans  = (a + (1LL<<k));
  ans >>= k;
  ans <<= k;
  return ans;
}

// aより大きく、末尾が「1、0がk個」で終わる最小の数を返す
static long long next2(long long a, int k) {
  long long ans = a;
  ans >>= (k + 1);
  ans += 1LL;
  ans <<= (k + 1);
  ans += (1LL << k);
  return ans;
}

static int ctz(long long a) {
  assert(a > 0);
  int ans = 0;
  while ((a&1) == 0) {
    ans++;
    a >>= 1;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> T(N + 1, -1);
  for (int n = 1; n <= N; n++) {
    cin >> T.at(n);
  }
  vector<long long> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    int k = T.at(n);
    A.at(n) = next1(A.at(n - 1), k);
    if (ctz(A.at(n)) != k) {
      A.at(n) = next2(A.at(n - 1), k);
    }
  }
  cout << A.at(N) << endl;
  return 0;
}
