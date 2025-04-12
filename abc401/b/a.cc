#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool login = false;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (S == "login") {
      login = true;
    } else if (S == "logout") {
      login = false;
    } else if (S == "public") {
    } else {
      if (login == false) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
