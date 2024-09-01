// https://www.youtube.com/watch?v=n1QdxjxIf2o&t=5692s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

struct Train {
  int a, b, s, t, i;
  Train(int a, int b, int s, int t, int i): a(a), b(b), s(s), t(t), i(i) {}
  bool operator<(const Train& rhs) const { return s < rhs.s; }
};

int main() {
  int N, M, X0;
  cin >> N >> M >> X0;
  vector<Train> trains;
  for (int i = 0; i < M; i++) {
    int A, B, S, T;
    cin >> A >> B >> S >> T;
    A--; B--;
    trains.emplace_back(A, B, S, T, i);
  }
  // Siの昇順に遅らせる時間Xiを求める
  sort(trains.begin(), trains.end());
  vector<int> X(M, 0);
  vector<int> maxVal(N, 0);  // maxX[n]: n番目の駅における最大のTi+Xi
  // pqs[n]: n番目の駅について、考えるべき(T, T+X)を昇順に並べたもの
  vector<priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > > pqs(N);
  for (auto [a, b, s, t, i]: trains) {
    // X[i]を求める
    if (i == 0) {
      X[i] = X0;
    } else {
      while (!pqs[a].empty()) {
        auto [nt, nval] = pqs[a].top();
        if (nt <= s) {
          maxVal[a] = max(maxVal[a], nval);
        } else {
          break;
        }
        pqs[a].pop();
      }
      X[i] = max(maxVal[a] - s, 0);
    }
    // 遅れの伝播
    pqs[b].push(make_pair(t, t + X[i]));
  }
  dump(X, 1);
  return 0;
}
