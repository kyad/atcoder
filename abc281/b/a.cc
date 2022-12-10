#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S.size() != 8) {
    cout << "No" << endl;
    return 0;
  }
  if (S[0] < 'A' || S[0] > 'Z') {
    cout << "No" << endl;
    return 0;
  }
  if (S[7] < 'A' || S[7] > 'Z') {
    cout << "No" << endl;
    return 0;
  }
  if (S[1] < '1' || S[1] > '9') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 2; i <= 6; i++) {
    if (S[i] < '0' || S[i] > '9') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
