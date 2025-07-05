#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    sum += A;
  }
  if (sum <= M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
