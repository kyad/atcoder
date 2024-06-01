#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  vector<int> D(201, -1);  // 0: 両方無い, 1:A, 2:B
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int j = 0; j < M; j++) {
    cin >> B.at(j);
  }
  for (int i = 0; i < N; i++) {
    D.at(A.at(i)) = 1;
  }
  for (int j = 0; j < M; j++) {
    D.at(B.at(j)) = 2;
  }
  int len = 0;
  bool ans = false;
  for (int k = 1; k <= 200; k++) {
    if (D.at(k) == -1) {
      continue;
    } else if (D.at(k) == 1) {   // A
      len++;
      if (len >= 2) {
        ans = true;
      }
    } else {  // B
      len = 0;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
