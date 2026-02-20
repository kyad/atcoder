#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long M;
  cin >> N >> M;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    sum += A;
  }
  bool ans = sum >= M;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
