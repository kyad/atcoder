#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  long long ans = 4e18;
  for (int start = 0; start < N; start++) {
    long long now = A * start;
    for (int l = 0; l < N / 2; l++) {
      int r = N - 1 - l;
      int l1 = (start + l) % N;
      int r1 = (start + r) % N;
      if (S[l1] != S[r1]) {
        now += B;
      }
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
