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

int dist(string S, string T) {
  int N = S.size();
  int d = 0;
  for (int n = 0; n < N; n++) {
    if (S.at(n) != T.at(n)) {
      d++;
    }
  }
  return d;
}

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S;
  cin >> T;
  string ans = "2";
  for (int bit = 0; bit < (1<<N); bit++) {
    string U;
    for (int i = 0; i < N; i++) {
      if ((bit>> i)&1) {
        U += '1';
      } else {
        U += '0';
      }
    }
    int d1 = dist(S, U);
    int d2 = dist(T, U);
    if (d1 == d2) {
      ans = min(ans, U);
    }
  }
  if (ans == "2") {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
