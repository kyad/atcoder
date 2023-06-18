#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<long long> A(N, 0);
  multiset<long long> S, T;
  for (int k = 0; k < K; k++) {
    S.insert(0);
  }
  for (int k = 0; k < N - K; k++) {
    T.insert(0);
  }
  T.insert(0);  // 番兵
  long long sum = 0;

  for (int qi = 0; qi < Q; qi++) {
    int X, Y;
    cin >> X >> Y;
    X--;
    // Remove prev = A[X]
    if (S.count(A[X]) > 0) {
      S.erase(S.find(A[X]));
      sum -= A[X];
      // T --> S
      long long now = *T.rbegin();
      S.insert(now);
      sum += now;
      T.erase(T.find(now));
    } else {
      T.erase(T.find(A[X]));
    }
    assert((int)S.size() == K);
    assert((int)T.size() == N - K - 1 + 1);
    // Add now Y
    A[X] = Y;
    if (Y > *S.begin()) {
      S.insert(Y);
      sum += Y;
      // S --> T
      long long now = *S.begin();
      S.erase(S.find(now));
      sum -= now;
      T.insert(now);
    } else {
      T.insert(Y);
    }
    assert((int)S.size() == K);
    assert((int)T.size() == N - K + 1);
    cout << sum << '\n';
  }
  return 0;
}
