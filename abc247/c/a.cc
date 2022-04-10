#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> S(65536);
  for (int i = 1; i <= 16; i++) {
    int j = (1<<(i - 1)) - 1;
    S.at(j) = i;
    for (int k = 0; k < j; k++) {
      S.at(j + 1 + k) = S.at(k);
    }
  }
  int N;
  cin >> N;
  int len = (1<<N) - 1;
  for (int i = 0; i < len; i++) {
    cout << S.at(i);
    if (i == len - 1) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}
