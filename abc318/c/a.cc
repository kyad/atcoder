#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  int N, D;
  long long P;
  cin >> N >> D >> P;
  vector<long long> F(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> F.at(n);
  }
  sort(F.begin(), F.end());
  vector<long long> S(F);
  for (int n = 1; n < N; n++) {
    S[n] += S[n - 1];
  }
  int X = ceildiv(N, D);
  long long ans = 4e18;
  for (int x = 0; x <= X; x++) {
    long long Y = 0;
    if (N - 1 - x * D >= 0) {
      Y = S.at(N - 1 - x * D);
    }
    long long Z = P * x;
    long long now = Y + Z;
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
