#include <iostream>
#include <vector>
using namespace std;

char change(char c) {
  if (c == '0') {
    return '1';
  } else {
    return '0';
  }
}

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S;
  cin >> T;
  int d = 0;
  for (int n = 0; n < N; n++) {
    if (S.at(n) != T.at(n)) {
      d++;
    }
  }
  if (d % 2) {
    cout << -1 << endl;
    return 0;
  }
  int D = d / 2;
  int res = d;
  int used = 0;
  string U;
  for (int n = 0; n < N; n++) {
    if (S.at(n) == T.at(n)) {
      U.push_back('0');
    } else {
      U.push_back(S.at(n));
    }
  }
  
  for (int n = 0; n < N; n++) {
    if (S[n] == T[n]) {
      continue;
    }
    if (D - used == res) {
      U[n] = change(U[n]);
      used++;
    } else {
      if (U[n] == '1') {
        U[n] = change(U[n]);
        used++;
      }
    }
    if (used >= D) {
      break;
    }
    res--;
  }
  cout << U << endl;
  return 0;
}
