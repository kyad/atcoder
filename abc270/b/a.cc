#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  if (X < 0) {
    X = -X;
    Y = -Y;
    Z = -Z;
  }
  int ans;
  if (0 < Y && Y < X) {
    if (Z < Y) {
      ans = abs(Z) + (Y - Z) + (X - Y);
    } else {
      ans = -1;
    }
  } else {
    ans = X;
  }    
  cout << ans << endl;
  return 0;
}
