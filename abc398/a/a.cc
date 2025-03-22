#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N % 2 == 1) {
    int a = N / 2;
    for (int i = 0; i < a; i++) {
      cout << '-';
    }
    cout << '=';
    for (int i = 0; i < a; i++) {
      cout << '-';
    }
  } else {
    int a = N / 2 - 1;
    for (int i = 0; i < a; i++) {
      cout << '-';
    }
    cout << '=';
    cout << '=';
    for (int i = 0; i < a; i++) {
      cout << '-';
    }
  }
  cout << endl;
  return 0;
}
