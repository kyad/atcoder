#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<int> C(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    int B;
    cin >> B;
    C.at(B) = i;
  }
  bool ans = true;
  for (int i = 1; i <= N; i++) {
    if (A.at(i) != C.at(i)) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
