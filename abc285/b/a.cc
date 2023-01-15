#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 1; i < N; i++) {
    int l = 0;
    for (int k = 0; k + i < N; k++) {
      if (S[k] == S[k + i]) {
        break;
      }
      l = (k + 1);
    }
    cout << l << endl;
  }
  return 0;
}
