#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<bool> is_loop;

vector<bool> seen1;
int loop_start;
bool dfs1(int u, int parent) {
  int ans = false;  // found loop: true
  seen1[u] = true;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    if (seen1[v]) {
      if (loop_start < 0) {  // found loop
        loop_start = v;
        ans = true;
      }
      continue;
    }
    bool now = dfs1(v, u);
    if (!ans) {
      if (v != loop_start) {
        ans = now;
      }
    }
  }
  is_loop[u] = ans;
  return ans;
}

vector<int> group;
int group_id;
void dfs2(int u, int parent) {
  group[u] = group_id;
  for (size_t i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v == parent) {
      continue;
    }
    if (is_loop[v]) {
      continue;
    }
    dfs2(v, u);
  }
}

int main() {
  int N;
  cin >> N;
  graph.resize(N);
  for (int n = 0; n < N; n++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  // DFS find loop
  is_loop.resize(N, false);
  seen1.resize(N, false);
  loop_start = -1;
  dfs1(0, -1);

  // DFS find group
  group.resize(N, -1);
  for (int u = 0; u < N; u++) {
    if (!is_loop[u]) {
      continue;
    }
    group_id = u;
    dfs2(u, -1);
  }

  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int X, Y;
    cin >> X >> Y;
    X--; Y--;
    if (group[X] == group[Y] && (group[X] >= 0)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
