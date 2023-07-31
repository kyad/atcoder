#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int M = 100;
  vector<vector<vector<int> > > cell(M, vector<vector<int> >(M, vector<int>(M, -1)));
  for (int n = 0; n < N; n++) {
    int X1, Y1, Z1, X2, Y2, Z2;
    cin >> X1 >> Y1 >> Z1 >> X2 >> Y2 >> Z2;
    for (int x = X1; x < X2; x++) {
      for (int y = Y1; y < Y2; y++) {
        for (int z = Z1; z < Z2; z++) {
          cell[x][y][z] = n;
        }
      }
    }
  }
  vector<set<int> > st(N);
  const int dx[6] = {1, 0, 0, -1, 0, 0};
  const int dy[6] = {0, 1, 0, 0, -1, 0};
  const int dz[6] = {0, 0, 1, 0, 0, -1};
  for (int x = 0; x < M; x++) {
    for (int y = 0; y < M; y++) {
      for (int z = 0; z < M; z++) {
        if (cell[x][y][z] < 0) {
          continue;
        }
        const int n = cell[x][y][z];
        for (int k = 0; k < 6; k++) {
          const int nx = x + dx[k];
          const int ny = y + dy[k];
          const int nz = z + dz[k];
          if (nx < 0 || nx >= M || ny < 0 || ny >= M || nz < 0 || nz >= M) {
            continue;
          }
          if (cell[nx][ny][nz] == n) {
            continue;
          }
          if (cell[nx][ny][nz] == -1) {
            continue;
          }
          st[n].insert(cell[nx][ny][nz]);
        }
      }
    }
  }
  for (int n = 0; n < N; n++) {
    cout << st[n].size() << '\n';
  }
  return 0;
}
