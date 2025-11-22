#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// xをbase進数で見た時の桁数を返す
int digits(long long x, int base) { int d = 0; while (x > 0) { x /= base; d++; } return d; }

using lll = __int128;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int D = 10;  // A[i]の最大桁数
  vector<map<long long, int> > mp(D + 1);
  for (int i = 0; i < N; i++) {
    int d = digits(A.at(i), 10);
    long long b = A.at(i) % M;
    mp.at(d)[b]++;
  }
  for (int d = 1; d <= D; d++) {
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    lll a = A.at(i);
    for (int d = 1; d <= D; d++) {
      a *= 10;
      long long aa = a % M;
      long long b = (M - aa) % M;
      long long now = mp.at(d)[b];
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
