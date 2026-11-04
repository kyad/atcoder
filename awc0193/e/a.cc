#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  const int M = 2e5+3;
  vector<int> imos(M + 2, 0);
  int mode = 0;
  int left = -1;
  int top = -1;
  for (int i = 0; i < N - 1; i++) {
    if (mode == 0) {
      if (S.at(i) < S.at(i + 1)) {
        mode = 1;
        left = i;
      }
    } else if (mode == 1) {
      if (S.at(i) < S.at(i + 1)) {
        // OK
      } else if (S.at(i) > S.at(i + 1)) {
        mode = 2;
        top = i;
      } else{ 
        // NG
        mode = 0;
        left = -1;
        top = -1;
      }
    } else if (mode == 2) {
      if (S.at(i) > S.at(i + 1)) {
        // OK
      } else {
        int right = i;
        int L = top - left;
        int R = right - top;
        imos.at(3)++;
        imos.at(3 + L)--;
        imos.at(3 + R)--;
        imos.at(3 + L + R)++;
        if (S.at(i) < S.at(i + 1)) {
          mode = 1;
          left = i;
        } else {
          mode = 0;
          left = -1;
        }
      }
    }
  }
  if (mode == 2) {
    int right = N - 1;
    int L = top - left;
    int R = right - top;
    imos.at(3)++;
    imos.at(3 + L)--;
    imos.at(3 + R)--;
    imos.at(3 + L + R)++;
  }
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i <= M; i++) {
      imos.at(i + 1) += imos.at(i);
    }
  }
  for (int qi = 0; qi < Q; qi++) {
    int K;
    cin >> K;
    int ans = imos.at(K);
    cout << ans << '\n';
  }
  return 0;
}
