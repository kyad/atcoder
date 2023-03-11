#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  for (int i = 0; i < N; i += 2) {
    swap(S[i], S[i + 1]);
  }
  cout << S << endl;
  return 0;
}
