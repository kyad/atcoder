#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<bool> > G(N, vector<bool>(N, false));
  vector<vector<int> > graph(N);
  for (int i = 0; i < N - 1; i++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    G.at(U).at(V) = true;
    G.at(V).at(U) = true;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  set<pair<int, int> > st;
  // 偶閉路をつくれる辺を列挙
  for (int u = 0; u < N; u++) {
    for (int v = u + 1; v < N; v++) {
      if (G.at(u).at(v) == true) {
        continue;
      }
      // // 一旦(u, v)を追加
      // graph.at(u).push_back(v);
      // graph.at(v).push_back(u);

      // BFS
      int s = u;  // 探索開始ノード
      queue<int> todo;
      vector<int> dist(N, -1);
      dist.at(s) = 0;
      todo.push(s);
      while (!todo.empty()) {
        int u = todo.front();
        todo.pop();
        for (int v : graph.at(u)) {
          if (dist.at(v) < 0) {
            dist.at(v) = dist.at(u) + 1;
            todo.push(v);
          }
        }
      }

      assert(dist.at(v) >= 0);
      if (dist.at(v) % 2 == 1) {  // 偶閉路を追加できる
        st.insert(make_pair(u, v));
      }

      // // 一旦追加した(u, v)を削除
      // graph.at(u).pop_back();
      // graph.at(v).pop_back();
    }
  }

  int K = st.size();
  bool turn;
  if (K % 2 == 1) {
    cout << "First" << endl;
    turn = true;
  } else {
    cout << "Second" << endl;
    turn = false;
  }
  while (true) {
    if (turn == true) {
      assert(!st.empty());
      int u = st.begin()->first + 1;
      int v = st.begin()->second + 1;
      cout << u << ' ' << v << endl;
      st.erase(st.begin());
    } else {
      int u, v;
      cin >> u >> v;
      if (u == -1 && v == -1) {
        return 0;  // 終了
      }
      u--; v--;
      // u < vにする
      if (v < u) {
        swap(u, v);
      }
      pair<int, int> p = make_pair(u, v);
      assert(st.contains(p));
      st.erase(p);
    }
    turn = !turn;
  }
  return 0;
}
