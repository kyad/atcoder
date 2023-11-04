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
  for (int n = 0; n < N - 1; n++) {
    if (S[n] == 'a' && S[n + 1] == 'b') {
      cout << "Yes" << endl;
      return 0;
    }
    if (S[n] == 'b' && S[n + 1] == 'a') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
