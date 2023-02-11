#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  string T;
  for (size_t i = 0; i < S.size(); i++) {
    if (S[i] == '0') {
      T.push_back('1');
    } else {
      T.push_back('0');
    }
  }
  cout << T << endl;
  return 0;
}
