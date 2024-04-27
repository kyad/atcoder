#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<string> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] != B[i][j]) {
        cout << (i + 1) << ' ' << (j + 1) << endl;
        return 0;
      }
    }
  }
  return 1;
}
