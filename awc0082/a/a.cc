#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long ans = 0;
  for (int j = 0; j < M; j++) {
    int S, P;
    long long D;
    cin >> S >> P >> D;
    P--;
    long long price;
    if (S == 1) {
      price = max(A.at(P) - K, 0LL);
    } else {
      price = A.at(P);
    }
    long long now = price * D;
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
