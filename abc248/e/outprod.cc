#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long outprod2(long long ax, long long ay, long long bx, long long by) {
  return ax * by - ay * bx;
}

int main() {
  int N, K;
  cin >> N >> K;
  if (K == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  vector<long long> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  int ans = 0;
  vector<set<int> > used(N);
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      if (used[a].count(b) > 0 || used[b].count(a) > 0) {
        continue;
      }
      int count = 2;
      vector<int> line;
      for (int c = b + 1; c < N; c++) {
        if (used[c].count(a) > 0 || used[a].count(c) > 0) {
          continue;
        }
        if (used[c].count(b) > 0 || used[b].count(c) > 0) {
          continue;
        }
        long long bx = X[b] - X[a];
        long long by = Y[b] - Y[a];
        long long cx = X[c] - X[a];
        long long cy = Y[c] - Y[a];
        long long oprod = outprod2(bx, by, cx, cy);
        if (oprod == 0) {
          count++;
          line.push_back(c);
        }
      }
      if (count >= K) {
        ans++;
      }
      for (size_t i = 0; i < line.size(); i++) {
        int c = line[i];
        used[a].insert(c);
        used[a].insert(b);
        used[b].insert(a);
        used[b].insert(c);
        used[c].insert(a);
        used[c].insert(b);
      }
      for (size_t i = 0; i < line.size(); i++) {
        int c = line[i];
        for (size_t j = i + 1; j < line.size(); j++) {
          int d = line[j];
          used[c].insert(d);
          used[d].insert(c);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
