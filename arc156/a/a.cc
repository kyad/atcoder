#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int even2 = 0;
  int count = 0;
  int now = 0;
  for (int n = 0; n < N; n++) {
    if (S[n] == '1') {
      now++;
      count++;
    } else {
      if (now == 2) {
        even2++;
      }
      now = 0;
    }
  }
  if (now == 2) {
    even2++;
  }

  if (count % 2 == 1) {
    cout << -1 << endl;
    return;
  }

  if (count == 2 && even2 == 1) {
    if (N == 3) {
      cout << -1 << endl;
      return;
    } else if (N == 4 && S == "0110") {
      cout << 3 << endl;
      return;
    }
    cout << 2 << endl;
    return;
  }

  int ans = count / 2;
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
