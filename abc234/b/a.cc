#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int n = 0; n < N; n++) {
    cin >> x.at(n) >> y.at(n);
  }
  int m = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      m = max(m, (x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j)));
    }
  }
  cout << setprecision(14) << sqrt(m) << endl;
  return 0;
}
