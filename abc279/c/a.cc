#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H), T(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  for (int y = 0; y < H; y++) {
    cin >> T.at(y);
  }
  vector<vector<char> > A(W, vector<char>(H));
  vector<vector<char> > B(W, vector<char>(H));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      A[x][y] = S[y][x];
      B[x][y] = T[y][x];
    }
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  cout << (A == B ? "Yes" : "No") << endl;
  return 0;
}
