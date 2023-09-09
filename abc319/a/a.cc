#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  if (S == "tourist") {
    ans = 3858;
  } else if (S == "ksun48") {
    ans = 3679;
  } else if (S == "Benq") {
    ans = 3658;
  } else if (S == "Um_nik") {
    ans = 3648;
  } else if (S == "apiad") {
    ans = 3638;
  } else if (S == "Stonefeang") {
    ans = 3630;
  } else if (S == "ecnerwala") {
    ans = 3613;
  } else if (S == "mnbvmar") {
    ans = 3555;
  } else if (S == "newbiedmy") {
    ans = 3516;
  } else if (S == "semiexp") {
    ans = 3481;
  }
  cout << ans << endl;
  return 0;
}
