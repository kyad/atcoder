#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  reverse(S.begin(), S.end());
  for (int n = 0; n < N; n++) {
    cout << S[n] << endl;
  }
  return 0;
}
