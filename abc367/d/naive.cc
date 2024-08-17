#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  int M;
  cin >> N >> M;
  vector<long long> A(2 * N + 1, 0);
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    A.at(i) = a;
    A.at(i + N) = a;
  }
  vector<long long> S(2 * N + 1, 0);
  for (int i = 1; i <= 2 * N; i++) {
    S.at(i) = S.at(i - 1) + A.at(i);
  }
  long long ans = 0;
  for (int s = 1; s <= N; s++) {
    for (int t = s + 1; t <= s + N - 1; t++) {
      if ((S.at(t) - S.at(s)) % M == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
