#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int left = 1;
  int right = N;
  while (right - left > 1) {
    int mid = (left + right) / 2;
    cout << "? " << mid << endl;
    int S;
    cin >> S;
    if (S == 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << "! " << left << endl;
  return 0;
}
