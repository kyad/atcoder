#include <iostream>
#include <vector>
using namespace std;

int H1, W1, H2, W2;
vector<vector<int> > A;
vector<vector<int> > B;

bool solve(int by, int bx) {
  vector<vector<int> > C;
  for (int y = 0; y < H1; y++) {
    if (((by >> y)&1) == 0) {
      continue;
    }
    vector<int> line;
    for (int x = 0; x < W1; x++) {
      if (((bx >> x)&1) == 0) {
        continue;
      }
      line.push_back(A[y][x]);
    }
    C.push_back(line);
  }
  return C == B;
}

int main() {
  cin >> H1 >> W1;
  A.resize(H1, vector<int>(W1, 0));
  for (int y = 0; y < H1; y++) {
    for (int x = 0; x < W1; x++) {
      cin >> A[y][x];
    }
  }
  cin >> H2 >> W2;
  B.resize(H2, vector<int>(W2, 0));
  for (int y = 0; y < H2; y++) {
    for (int x = 0; x < W2; x++) {
      cin >> B[y][x];
    }
  }
  for (int by = 0; by < (1<<H1); by++) {
    for (int bx = 0; bx < (1<<W1); bx++) {
      if (solve(by, bx)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
