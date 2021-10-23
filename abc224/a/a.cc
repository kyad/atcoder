#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int len = (int)S.size();
  if (S[len - 2] == 'e' && S[len - 1] == 'r') {
    cout << "er" << endl;
  } else {
    cout << "ist" << endl;
  }
  return 0;
}
