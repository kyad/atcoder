#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> count(26, 0);
  for (int i = 0; i < 3; i++) {
    count[S[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] == 1) {
      char c = 'a' + i;
      cout << c << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
