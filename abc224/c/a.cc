#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  int ans = 0;
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      for (int c = b + 1; c < N; c++) {
        int x1 = X.at(c) - X.at(a);
        int y1 = Y.at(c) - Y.at(a);
        int x2 = X.at(b) - X.at(a);
        int y2 = Y.at(b) - Y.at(a);
        if (x1 * y2 != x2 * y1) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
