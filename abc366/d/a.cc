#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<vector<long long> > > A(N + 1, vector<vector<long long> >(N + 1, vector<long long>(N + 1, 0)));
  for (int x = 1; x <= N; x++) {
    for (int y = 1; y <= N; y++) {
      for (int z = 1; z <= N; z++) {
        cin >> A.at(x).at(y).at(z);
      }
    }
  }
  // A[x][y][z] (0<=x, y, z<=N): (0, 0, 0)~(x, y, z)までの整数の和
  for (int y = 1; y <= N; y++) {
    for (int z = 1; z <= N; z++) {
      for (int x = 1; x <= N; x++) {
        A.at(x).at(y).at(z) += A.at(x - 1).at(y).at(z);
      }
    }
  }
  for (int x = 1; x <= N; x++) {
    for (int z = 1; z <= N; z++) {
      for (int y = 1; y <= N; y++) {
        A.at(x).at(y).at(z) += A.at(x).at(y - 1).at(z);
      }
    }
  }
  for (int x = 1; x <= N; x++) {
    for (int y = 1; y <= N; y++) {
      for (int z = 1; z <= N; z++) {
        A.at(x).at(y).at(z) += A.at(x).at(y).at(z - 1);
      }
    }
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int Lx, Rx, Ly, Ry, Lz, Rz;
    cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
    long long ans = A.at(Rx).at(Ry).at(Rz)
      - A.at(Lx - 1).at(Ry).at(Rz)
      - A.at(Rx).at(Ly - 1).at(Rz)
      - A.at(Rx).at(Ry).at(Lz - 1)
      + A.at(Lx - 1).at(Ly - 1).at(Rz)
      + A.at(Rx).at(Ly - 1).at(Lz - 1)
      + A.at(Lx - 1).at(Ry).at(Lz - 1)
      - A.at(Lx - 1).at(Ly - 1).at(Lz - 1);
    cout << ans << '\n';
  }
  return 0;
}
