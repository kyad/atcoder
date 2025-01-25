#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  // r = A.at(1) / A.at(0);
  for (int i = 1; i < N - 1; i++) {
    if (A.at(1) * A.at(i) != A.at(0) * A.at(i + 1)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
