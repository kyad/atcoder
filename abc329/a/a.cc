#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  for (int n = 0; n < N; n++) {
    cout << S[n];
    if (n != N - 1) {
      cout << ' ';
    }  else {
      cout << '\n';
    }
  }
  return 0;
}
