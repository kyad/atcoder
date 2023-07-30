#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  vector<int> C(M);
  for (int m = 0; m < M; m++) {
    C[m] = -B[m];
  }
  sort(A.begin(), A.end());
  sort(C.begin(), C.end());
  auto check = [&](int X) -> bool {
    int a = upper_bound(A.begin(), A.end(), X) - A.begin();
    int b = upper_bound(C.begin(), C.end(), -X) - C.begin();
    return (a >= b);
  };
  const int INF = 1e9+2;
  int left = 0;  // NG
  int right = INF;  // OK
  while (right - left > 1) {
    int mid = (left + right) / 2;
    bool now = check(mid);
    if (now) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;
  return 0;
}
