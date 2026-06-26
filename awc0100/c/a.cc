#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L, Q;
  cin >> N >> L >> Q;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  auto OR = [&](string &A, const string &B) {
    for (int i = 0; i < L; i++) {
      if (A.at(i) == '1' || B.at(i) == '1') {
        A.at(i) = '1';
      } else {
        A.at(i) = '0';
      }
    }
  };
  for (int qi = 0; qi < Q; qi++) {
    string T(L, '0');
    int M;
    cin >> M;
    for (int j = 0; j < M; j++) {
      int c;
      cin >> c;
      c--;
      OR(T, S.at(c));
    }
    cout << T << '\n';
  }
  return 0;
}
