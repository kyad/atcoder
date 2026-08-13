#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(N);
  vector<long long> L(N);
  vector<vector<long long> > graph(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i) >> L.at(i);
    C.at(i)--;
    graph.at(C.at(i)).push_back(L.at(i));
  }
  long long ans = 0;
  for (int c = 0; c < N; c++) {
    int M = graph.at(c).size();
    long long now = 0;
    for (int i = 0; i < M; i++) {
      for (int j = i + 1; j < M; j++) {
        now += abs(graph.at(c).at(i) - graph.at(c).at(j));
      }
    }
    ans += now;
    
  }
  cout << ans << '\n';
  return 0;
}
