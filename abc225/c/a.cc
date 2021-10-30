#include <iostream>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int b0_prev = -1;
  for (int i = 0; i < N; i++) {
    int b0;
    cin >> b0;
    if (b0_prev >= 0 && b0 != b0_prev + 7) {
      cout << "No" << endl;
      return 0;
    }
    int b_prev = b0;
    int r_prev = (b0 - 1) % 7;
    for (int j = 0; j < M - 1; j++) {
      int b;
      cin >> b;
      if (b != b_prev + 1) {
        cout << "No" << endl;
        return 0;
      }
      b_prev = b;
      int r = (b - 1) % 7;
      if (r != r_prev + 1) {
        cout << "No" << endl;
        return 0;
      }
      r_prev = r;
    }
    b0_prev = b0;
  }
  cout << "Yes" << endl;
  return 0;
}
