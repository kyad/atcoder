#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> P(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  int k = -1;
  for (int n = 1; n <= N; n++) {
    if (P.at(n) == X) {
      k = n;
      break;
    }
  }
  cout << k << endl;
  return 0;
}
