#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int t_count = 0, t_n = 100000;
  int a_count = 0, a_n = 100000;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'T') {
      t_count++;
      t_n = n;
    } else {
      a_count++;
      a_n = n;
    }
  }
  char ans;
  if (t_count < a_count) {
    ans = 'A';
  } else if (t_count > a_count) {
    ans = 'T';
  } else {
    if (t_n < a_n) {
      ans = 'T';
    } else {
      ans = 'A';
    }
  }
  cout << ans << endl;
  return 0;
}
