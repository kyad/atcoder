#include <iostream>
#include <vector>
using namespace std;

const int M = 100000;

int f(int x) {
  int x0 = x;
  int y = 0;
  for (int i = 0; i < 5; i++) {
    y += (x % 10);
    x /= 10;
  }
  int z = (x0 + y) % M;
  return z;
}

int main() {
  int N;
  long long K;
  cin >> N >> K;
  // Doubling table
  vector<vector<int> > g(61, vector<int>(M));
  for (int x = 0; x < M; x++) {
    g[0][x] = f(x);
  }
  for (int i = 1; i < 61; i++) {
    for (int x = 0; x < M; x++) {
      g[i][x] = g[i - 1][g[i - 1][x]];
    }
  }
  int x = N;
  for (int i = 0; i < 61; i++) {
    if (K >> i & 1) {
      x = g[i][x];
    }
  }
  cout << x << endl;
  return 0;
}
