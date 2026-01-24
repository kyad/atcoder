#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long comb3(long long N) { return N * (N - 1) * (N - 2) / (3 * 2); }

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int j = 0; j < M; j++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  vector<long long> ans(N, 0);
  for (int i = 0; i < N; i++) {
    long long n = (long long)N - 1 - graph.at(i).size();
    if (n >= 3) {
      ans.at(i) = comb3(n);
    }
  }
  dump(ans);
  return 0;
}
