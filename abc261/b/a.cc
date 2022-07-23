#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  string ans = "correct";
  map<char, char> expected;
  expected['W'] = 'L';
  expected['L'] = 'W';
  expected['D'] = 'D';
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (A[i][j] != expected[A[j][i]]) {
        ans = "incorrect";
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
