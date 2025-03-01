#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool ans = true;
  int prev = -1;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    if (prev >= A) {
      ans = false;
    }
    prev = A;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
