#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  size_t i = 0;
  int count_x = 0;
  for (i = 0; i < S.size(); i++) {
    if (S[i] == 'x') {
      count_x++;
      if (count_x >= 3) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      break;
    }
  }
  size_t offset = i;
  for (; i < S.size(); i++) {
    if ((i - offset) % 3 == 0) {
      if (S[i] == 'x') {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (S[i] == 'o') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
