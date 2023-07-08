#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  for (int y = 0; y < N; y++) {
    cin >> A[y];
  }
  vector<string> B(A);
  // top
  for (int x = 1; x < N; x++) {
    B[0][x] = A[0][x - 1];
  }
  // right
  for (int y = 1; y < N; y++) {
    B[y][N - 1] = A[y - 1][N - 1];
  }
  // bottom
  for (int x = 0; x < N - 1; x++) {
    B[N - 1][x] = A[N - 1][x + 1];
  }
  // left
  for (int y = 0; y < N - 1; y++) {
    B[y][0] = A[y + 1][0];
  }
  for (int y = 0; y < N; y++) {
    cout << B[y] << endl;
  }
  return 0;
}
