#include <iostream>
using namespace std;

int main() {
  string S;
  int a, b;
  cin >> S;
  cin >> a >> b;
  a--;
  b--;
  char temp = S[b];
  S[b] = S[a];
  S[a] = temp;
  cout << S << endl;
  return 0;
}
