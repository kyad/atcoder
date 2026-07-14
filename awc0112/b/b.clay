#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<long long> D(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i);
  }
  vector<long long> Q(N, -1);
  for (int j = 0; j < M; j++) {
    int P;
    long long S;
    cin >> P >> S;
    P--;
    Q.at(P) = S;
  }
  for (int i = 0; i < N; i++) {
    K -= D.at(i);
    if (i == N - 1) {
      cout << "Yes" << endl;
      return 0;
    }
    if (Q.at(i) > 0 && Q.at(i) > K) {
      K = Q.at(i);
    }
    if (K <= 0) {
      cout << "No" << '\n';
      return 0;
    }
  }
  assert(false);
  return 0;
}
