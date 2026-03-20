#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    long long Q = A.at(i) / M;
    long long R = A.at(i) % M;
    cout << Q << ' ' << R << '\n';
  }
  return 0;
}
