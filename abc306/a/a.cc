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
  string T;
  for (int n = 0; n < N; n++) {
    T.push_back(S[n]);
    T.push_back(S[n]);
  }
  cout << T << endl;
  return 0;
}
