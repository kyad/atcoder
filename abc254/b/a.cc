#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        A[i][j] = 1;
      } else {
        A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cout << A[i][j];
      cout << (j == i ? '\n' : ' ');
    }
  }
  return 0;
}
