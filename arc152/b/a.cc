#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

int main() {
  int N, L;
  cin >> N >> L;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  int r = N - 1;
  int mn = L * 2;
  for (int l = 0; l <= N - 1; l++) {
    bool end = false;
    while (true) {
      if (r < 0) {
        end = true;
        break;
      }
      int nr = r - 1;
      if (nr < 0) {
        break;
      }
      int now = A[l] + A[nr];
      if (now < L) {
        break;
      }
      r = nr;
    }
    if (end) {
      break;
    }
    int now = A[l] + A[r] - L;
    chmin(mn, abs(now));  // `now` might be < 0
    if (r > 1) {
      int now = L - A[l] - A[r - 1];
      assert(now >= 0);
      chmin(mn, now);
    }
  }
  long long ans = ((long long)L + mn) * 2;
  cout << ans << endl;
  return 0;
}
