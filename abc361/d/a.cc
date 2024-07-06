#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int c2i(char c) {
  int ans;
  if (c == 'W') {
    ans = 1;
  } else if (c == 'B') {
    ans = 2;
  } else {
    ans = 0;
    assert(false);
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;

  auto str2state = [&](string S) {
    int state = 0;
    for (int i = 0; i < N + 2; i++) {
      state *= 3;
      if (i < (int)S.size()) {
        state += c2i(S.at(i));
      }
    }
    return state;
  };

  // BFS
  int s = str2state(S);  // 探索開始ノード

  // M = 3^(N + 2)
  int M = 1;
  for (int i = 0; i < N + 2; i++) {
    M *= 3;
  }

  auto state2array = [&](int state) {
    vector<int> a(N + 2);
    for (int i = 0; i < N + 2; i++) {
      a.at(N + 1 - i) = state % 3;
      state /= 3;
    }
    return a;
  };

  auto array2state = [&](vector<int> &a) {
    int state = 0;
    for (int i = 0; i < N + 2; i++) {
      state *= 3;
      state += a.at(i);
    }
    return state;
  };

  auto state2str = [&](int state) {
    vector<int> a = state2array(state);
    string S;
    for (int i = 0; i < N + 2; i++) {
      if (a.at(i) == 0) {
        S.push_back('.');
      } else if (a.at(i) == 1) {
        S.push_back('W');
      } else if (a.at(i) == 2) {
        S.push_back('B');
      } else {
        assert(false);
      }
    }
    return S;
  };

  queue<int> todo;
  vector<int> dist(M, -1);
  dist.at(s) = 0;
  todo.push(s);
  while (!todo.empty()) {
    int u = todo.front();
    todo.pop();
    // uからの遷移
    // まず配列を求める
    vector<int> a = state2array(u);
    // 0がある場所を見付ける
    int iz = -1;
    for (int i = 0; i <= N; i++) {
      if (a.at(i) == 0) {
        iz = i;
        break;
      }
    }
    assert(iz >= 0);
    assert(a.at(iz + 1) == 0);
    // 遷移する
    for (int i = 0; i <= N; i++) {
      if (iz - 1 <= i && i <= iz + 1) {
        continue;
      }
      // 次の状態 b, v
      vector<int> b(a);
      swap(b.at(i), b.at(iz));
      swap(b.at(i + 1), b.at(iz + 1));
      int v = array2state(b);
      
      if (dist.at(v) < 0) {
        dist.at(v) = dist.at(u) + 1;
        todo.push(v);
      }
    }
  }

  int t = str2state(T);
  int ans = dist.at(t);

  cout << ans << endl;
  return 0;
}
