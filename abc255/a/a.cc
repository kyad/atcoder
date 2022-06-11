#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  vector<vector<int> > A(2, vector<int>(2));
  for (int y = 0; y < 2; y++) {
    for (int x = 0; x < 2; x++) {
      cin >> A[y][x];
    }
  }
  cout << A[R-1][C-1] << endl;
  return 0;
}
