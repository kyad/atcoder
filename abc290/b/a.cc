#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  string T;
  for (int n = 0; n < N; n++) {
    char now = 'x';
    if (S[n] == 'o') {
      if (K > 0) {
        now = 'o';
        K--;
      }
    }
    T.push_back(now);
  }
  cout << T << endl;
  return 0;
}
