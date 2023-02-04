#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int n = 0; n < N; n++) {
    int A, B;
    cin >> A >> B;
    cout << (A + B) << endl;
  }
  return 0;
}
