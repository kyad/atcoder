#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  string smax(S);
  string smin(S);
  int len = (int)S.size();
  for (int i = 0; i < len; i++) {
    string T;
    for (int k = 0; k < len - 1; k++) {
      T.push_back(S[k + 1]);
    }
    T.push_back(S[0]);
    smax = max(smax, T);
    smin = min(smin, T);
    S = T;
  }
  cout << smin << endl;
  cout << smax << endl;
  return 0;
}
