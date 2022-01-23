#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = N * (N + 1) / 2 * 4;
  for (int n = 0; n < 4 * N - 1; n++) {
    int A;
    cin >> A;
    sum -= A;
  }
  cout << sum << endl;
  return 0;
}
