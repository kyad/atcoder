#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i)--;
  }
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }

  // B[k]: クラスkの人数
  vector<int> B(K, 0);
  for (int i = 0; i < N; i++) {
    B.at(A.at(i))++;
  }

  // C[j]: 人数がbのクラス数
  vector<int> C(N + 1, 0);
  for (int k = 0; k < K; k++) {
    int b = B.at(k);
    C.at(b)++;
  }
  int b0 = -1;
  int b1 = -1;
  for (int b = N; b >= 0; b--) {  // 人数
    if (C.at(b) != 0) {
      if (b0 < 0) {
        b0 = b;
      } else if (b1 < 0) {
        b1 = b;
        break;
      }
    }
  }
  assert(b0 >= 0);
  if (b1 == -1) {
    cout << C.at(b0) << endl;
    return 0;
  }

  if (b0 - b1 == 1) {
    cout << C.at(b0) + C.at(b1) << endl;
  } else {
    cout << C.at(b0) << endl;
  }
  return 0;
}
