#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = -1;
  for (int n = 0; n < N; n++) {
    int H;
    cin >> H;
    if (H <= ans) {
      break;
    }
    ans = H;
  }
  cout << ans << endl;
  return 0;
}
