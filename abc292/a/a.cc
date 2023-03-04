#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  string T(S);
  for (size_t i = 0; i < S.size(); i++) {
    T[i] = S[i] + ('A' - 'a');
  }
  cout << T << endl;
  return 0;
}
