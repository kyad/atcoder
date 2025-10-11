#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long f(long long A) {
  long long ans = 0;
  while (A > 0) {
    long long now = A % 10;
    ans += now;
    A /= 10;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(101, -1);
  vector<long long> B(101, -1);
  // A[0]
  A.at(0)= 1;
  B.at(0) = f(A.at(0));
  for (int i = 1; i <= 100; i++) {
    A.at(i) = 0;
    for (int j = 0; j < i; j++) {
      A.at(i) += B.at(j);
    }
    B.at(i) = f(A.at(i));
  }
  cout << A.at(N) << endl;
  return 0;
}
