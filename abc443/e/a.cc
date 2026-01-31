#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, C;
    cin >> N >> C;
    C--;
    vector<string> S(N);
    for (int y = 0; y < N; y++) {
      cin >> S.at(y);
    }
    vector<int> h(N, N);
    for (int x = 0; x < N; x++) {
      for (int y = N - 1; y >= 0; y--) {
        if (S.at(y).at(x) == '.') {
          h.at(x) = y;
        } else {
          break;
        }
      }
    }
    // BFS
    const int dx[3] = {-1,  0, +1};
    queue<pair<int, int> > todo;
    vector<vector<int> > dist(N, vector<int>(N, -1));
    dist.at(N - 1).at(C) = 0;
    todo.push(make_pair(N - 1, C));
    while (!todo.empty()) {
      auto [y, x] = todo.front();
      todo.pop();
      for (int k = 0; k < 3; k++) {
        int ny = y - 1;
        int nx = x + dx[k];
        if (ny < 0 || nx < 0 || nx >= N) {
          continue;
        }
        // 進める条件
        if (S[ny][nx] == '.') {
          // OK
          if (dist.at(ny).at(nx) < 0) {
            dist.at(ny).at(nx) = dist.at(y).at(x) + 1;
            todo.push(make_pair(ny, nx));
          }
        } else if (h.at(nx) <= N - abs(nx - C) && ny + 1 == h.at(nx)) {
          // OK
          for (int yy = 0; yy <= ny; yy++) {
            if (dist.at(yy).at(nx) < 0) {
              dist.at(yy).at(nx) = dist.at(yy + 1).at(x) + 1;
              todo.push(make_pair(yy, nx));
            }
          }
        } else {
          // NG
          continue;
        }
      }
    }
    string ans;
    for (int x = 0; x < N; x++) {
      if (dist.at(0).at(x) >= 0) {
        ans.push_back('1');
      } else {
        ans.push_back('0');
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
