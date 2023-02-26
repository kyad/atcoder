#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int i = 0;
  for (i = 0; i < N; i++) {
    if (S[i] >= 'A' && S[i] <= 'Z') {
      break;
    }
  }
  cout << (i + 1) << endl;
  return 0;
}
