#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int ans = -1;
  for (int i = C; i <= B; i += C) {
    if (i < A) {
      continue;
    }
    ans = i;
    break;
  }
  cout << ans << endl;
  return 0;
}
