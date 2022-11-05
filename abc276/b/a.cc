#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N + 1);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  for (int i = 1; i <= N; i++) {
    sort(graph[i].begin(), graph[i].end());
    cout << graph[i].size();
    for (int u : graph[i]) {
      cout << ' ' << u;
    }
    cout << '\n';
  }
  return 0;
}
