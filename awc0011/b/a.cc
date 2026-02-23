#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  char c1, c2;
  cin >> c1 >> c2;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  vector<string> ans(H * K);
  for (int y = 0; y < H * K; y++) {
    string line;
    for (int x = 0; x < W * K; x++) {
      if (S.at(y / K).at(x / K) == '#') {
        line.push_back(c1);
      } else {
        line.push_back(c2);
      }
    }
    cout << line << '\n';
  }
  return 0;
}
