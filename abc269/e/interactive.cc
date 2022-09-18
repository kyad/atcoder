#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  auto solve = [&](int dir) {
    int left = 0;  // OK
    int right = N;  // NG
    while (right - left > 1) {
      int mid = (left + right) / 2;
      int A = 1;
      int B = N;
      int C = 1;
      int D = N;
      if (dir == 0) {
        A = left + 1;
        B = mid;
      } else {
        C = left + 1;
        D = mid;
      }
      cout << "? " << A << " " << B << " " << C << " " << D << " " << endl;
      int T;
      cin >> T;
      if (T == -1) {
        exit(1);
      }
      int expected = mid - left;
      if (T == expected) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return right;
  };
  int X = solve(0);
  int Y = solve(1);
  cout << "! " << X << " " << Y << endl;
  return 0;
}
