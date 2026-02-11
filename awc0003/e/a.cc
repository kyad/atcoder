#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  long long sumW = 0;
  long long sumC = 0;
  vector<long long> W(N), C(M);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
    sumW += W.at(i);
  }
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  for (int j = 0; j < M; j++) {
    cin >> C.at(j);
    sumC += C.at(j);
  }
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  if (sumW > sumC) {
    cout << "No" << endl;
    return 0;
  }
  if (W.at(N - 1) > C.at(0)) {
    cout << "No" << endl;
    return 0;
  }
  // C: のこり
  auto f = [&](auto f, int i) -> bool {
    if (i == N) {
      return true;
    }
    // iをどのトラックに入れるか
    for (int j = 0; j < M; j++) {
      // iをトラックjに入れる
      if (C.at(j) < W.at(i)) {
        continue;
      }
      C.at(j) -= W.at(i);
      if (f(f, i + 1) == true) {
        return true;
      }
      C.at(j) += W.at(i);
    }
    return false;
  };
  bool ans = f(f, 0);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
