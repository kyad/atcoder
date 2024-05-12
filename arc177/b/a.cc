#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string U(N, '0');
  string T;  // ans
  auto f = [&](char c) {  // c == '0' or '1'
    int i = c - '0';
    int ni = 1 - i;
    int nc = '0' + ni;
    for (int i = 0; i < N; i++) {
      if (U.at(i) == c) {
        U.at(i) = nc;
        return;
      }
    }
    assert(false);
  };
  for (int k = N - 1; k >= 0; k--) {
    while (S.at(k) != U.at(k)) {
      if (S.at(k) == '1') {
        T.push_back('A');
        f('0'); 
      } else {
        T.push_back('B');
        f('1');
      }
    }
  }
  int M = T.size();
  cout << M << endl;
  cout << T << endl;
  return 0;
}
