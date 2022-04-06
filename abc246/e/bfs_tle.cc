// https://atcoder.jp/contests/abc246/tasks/abc246_e
// |V|=N^2=1500*1500=2.25*10^6
// |E|=|V|*N=10^9
// BFSだとO(|V|+|E|)なのでTLE
// https://atcoder.jp/contests/abc246/editorial/3728 や
// https://note.com/syamashi/n/n5d0141e59ca9 のような枝刈りをしてO(|V|)になる

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int AX, AY;
  cin >> AY >> AX;
  AX--;
  AY--;
  int BX, BY;
  cin >> BY >> BX;
  BX--;
  BY--;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  // BFS
  queue<pair<int, int> > todo;
  vector<vector<int> > dist(N, vector<int>(N, -1));
  todo.push(make_pair(AY, AX));
  dist[AY][AX] = 0;
  while (!todo.empty()) {
    int y = todo.front().first;
    int x = todo.front().second;
    todo.pop();
    const int dy[4] = {1, 1, -1, -1};
    const int dx[4] = {1, -1, 1, -1};
    const int mx[4] = {min(N - x - 1, N - y - 1),
                       min(x, N - y - 1),
                       min(N - x - 1, y),
                       min(x, y)};
    for (int k = 0; k < 4; k++) {
      for (int d = 1; d <= mx[k]; d++) {
        int ny = y + dy[k] * d;
        int nx = x + dx[k] * d;
        if (dist[ny][nx] >= 0) {
          continue;
        }
        if (S[ny][nx] == '#') {
          break;
        }
        dist[ny][nx] = dist[y][x] + 1;
        todo.push(make_pair(ny, nx));
      }
    }
  }
  cout << dist[BY][BX] << endl;
  return 0;
}
