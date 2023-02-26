#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(5 * N);
  for (int n = 0; n < 5 * N; n++) {
    cin >> X.at(n);
  }
  double sum = 0;
  sort(X.begin(), X.end());
  for (int n = 0; n < 3 * N; n++) {
    int i = n + N;
    sum += X.at(i);
  }
  double ans = sum / (3 * N);
  cout << setprecision(15) << ans << endl;
  return 0;
}
