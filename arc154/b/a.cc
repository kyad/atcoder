#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  vector<int> cntS(26, 0), cntT(26, 0);
  for (int n = 0; n < N; n++) {
    cntS[S[n] - 'a']++;
    cntT[T[n] - 'a']++;
  }
  if (cntS != cntT) {
    cout << -1 << endl;
    return 0;
  }

  int i = N - 1;
  for (int j = N - 1; j >= 0; j--) {
    if (T[j] == S[i]) {
      i--;
    }
  }
  cout << (i+1) << endl;
  return 0;
}
