#include <iostream>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    for (int a = 0; a < A; a++) {
      for (int j = 0; j < N; j++) {
        char c = ((i + j) % 2 == 0 ? '.' : '#');
        for (int b = 0; b < B; b++) {
          cout << c;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
