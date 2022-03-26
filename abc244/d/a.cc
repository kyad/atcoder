#include <iostream>
#include <vector>
using namespace std;


int char_to_int(char c) {
  int ans;
  if (c == 'R') {
    ans = 0;
  } else if (c == 'G') {
    ans = 1;
  } else {
    ans = 2;
  }
  return ans;
}

int solve(char c1, char c2, char c3) {
  int a1 = char_to_int(c1);
  int a2 = char_to_int(c2);
  int a3 = char_to_int(c3);
  int ans = 1;
  if (a1 == 0 && a2 == 1 && a3 == 2) {
    ans = 0;
  } else if (a1 == 1 && a2 == 2 && a3 == 0) {
    ans = 0;
  } else if (a1 == 2 && a2 == 0 && a3 == 1) {
    ans = 0;
  }
  return ans;
}


int main() {
  char S1, S2, S3;
  cin >> S1 >> S2 >> S3;
  char T1, T2, T3;
  cin >> T1 >> T2 >> T3;
  int s = solve(S1, S2, S3);
  int t = solve(T1, T2, T3);
  cout << (s == t ? "Yes" : "No") << endl;
  return 0;
}
