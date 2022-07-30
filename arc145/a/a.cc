#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string ans;
  if (N == 2) {
    if (S == "AA" || S == "BB") {
      ans = "Yes";
    } else {
      ans = "No";
    }
  } else {
    if (S[0] == 'B' || S[N - 1] == 'A') {
      ans = "Yes";
    } else {
      ans = "No";
    }
  }
  cout << ans << endl;
  return 0;
}
