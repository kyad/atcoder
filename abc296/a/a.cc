#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  const string str[2] = {"FM", "MF"};
  for (int k = 0; k < 2; k++) {
    bool ok = true;
    for (int n = 0; n < N; n++) {
      if (S[n] != str[k][n%2]) {
        ok = false;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
