#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N;
  string S, T;
  cin >> N;
  cin >> S >> T;
  map<string, int> dist;

  // bfs
  queue<string> todo;
  dist[S] = 0;
  todo.push(S);
  while (!todo.empty()) {
    string v = todo.front();
    todo.pop();
    //hr;print(v);
    for (int i = 1; i < N; i++) {
      string x = v.substr(1, i) + v.substr(0, 1) + v.substr(1 + i, N - 1);
      //print(x);
      if (dist.count(x) == 0) {
	dist[x] = dist[v] + 1;
	todo.push(x);
        if (x == T) {
          goto end;
        }
      }
    }
    //print(todo);
    //print(dist);
  }
 end:
  int ans;
  if (dist.count(T) == 0) {
    ans = -1;
  } else {
    ans = dist[T];
  }
  cout << ans << endl;
  return 0;
}
