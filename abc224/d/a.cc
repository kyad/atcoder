// https://atcoder.jp/contests/abc224/tasks/abc224_d

#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int M;
  cin >> M;
  map<vector<int>, int> dist;
  vector<vector<int> > graph(9);
  for (int m = 0; m < M; m++) {
    int u, v;
    cin >> u >> v;
    graph[u - 1].push_back(v - 1);
    graph[v - 1].push_back(u - 1);
  }
  vector<int> start(9, 8);
  for (int i = 0; i < 8; i++) {
    int p;
    cin >> p;
    start[p - 1] = i;
  }
  // BFS
  queue<vector<int> > todo;
  todo.push(start);
  dist[start] = 0;
  int ans = -1;
  vector<int> last(9);
  for (int i = 0; i < 9; i++) {
    last[i] = i;
  }
  while (!todo.empty()) {
    vector<int> board = todo.front();
    todo.pop();
    if (board == last) {
      ans = dist[board];
      break;
    }
    int idx = 0;
    for (idx = 0; idx < 9; idx++) {
      if (board[idx] == 8) {
        break;
      }
    }
    for (size_t i = 0; i < graph[idx].size(); i++) {
      int v = graph[idx][i];
      vector<int> next_board(board);
      swap(next_board[idx], next_board[v]);
      if (dist.count(next_board) == 0) {
        todo.push(next_board);
        dist[next_board] = dist[board] + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
