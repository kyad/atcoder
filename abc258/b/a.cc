#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<long long> > A(N, vector<long long>(N));
  for (int n = 0; n < N; n++) {
    string line;
    cin >> line;
    for (int x = 0; x < N; x++) {
      A[n][x] = line[x] - '0';
    }
  }
  long long ans = 0;
  for (int y0 = 0; y0 < N; y0++) {
    for (int x0 = 0; x0 < N; x0++) {
      const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
      const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
      for (int k = 0; k < 8; k++) {
        long long now = 0;
        int y = y0;
        int x = x0;
        for (int i = 0; i < N; i++) {
          now += A[y][x];
          if (i != N - 1) {
            now *= 10;
          }
          y += (N + dy[k]);
          y %= N;
          x += (N + dx[k]);
          x %= N;
        }
        ans = max(ans, now);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
