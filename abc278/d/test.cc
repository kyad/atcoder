#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 200000;
  for (int n = 0; n < N; n++) {
    vector<int> A(N, 0);
    swap(A[0], A[2]);
  }
  return 0;
}
