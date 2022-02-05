#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long a, s;
    cin >> a >> s;
    if (s < a) {
      cout << "No" << endl;
      continue;
    }
    if ((a & (s - a)) == a) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
