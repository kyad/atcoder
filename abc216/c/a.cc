#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N;
  cin >> N;
  string ans = "";
  while (N != 1) {
    long long r = N % 2;
    if (r == 1) {
      ans = "BA" + ans;
    } else {
      ans = "B" + ans;
    }
    N /= 2;
  }
  ans = "A" + ans;
  cout << ans << endl;
  return 0;
}
