#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost;

int main() {
  multiprecision::cpp_int X;
  cin >> X;
  multiprecision::cpp_int ans = 0;
  while (X > 0) {
    ans += X;
    X /= 10;
  }
  cout << ans << endl;
  return 0;
}
