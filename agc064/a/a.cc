#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  cin >> N;
  deque<int> q;
  auto push2 = [&](int n) {
    q.push_front(n); q.push_back(n);
  };
  auto f = [&](auto f, int n) -> void {
    if (n == 1) {
      q.push_back(1);
      return;
    } else if (n == 2) {
      push2(2);
      q.push_back(1);
      return;
    } else if (n == 3) {
      push2(3);
      push2(2);
      q.push_front(3); q.push_back(1);
      return;
    } else if (n == 4) {
      push2(4);
      push2(3);
      push2(4);
      push2(2);
      q.push_front(3); q.push_back(1);
      return;
    }

    // 共通
    for (int i = 0; i < n / 2 - 1; i++) {
      push2(n);
      push2(n - 1);
    }
    push2(n);

    if (n % 2 == 0) { // 偶数からスタート
      push2(n - 2);
      q.push_front(n - 1); q.push_back(n - 3);
    } else {  // 奇数からスタート
      q.push_back(n - 2);
      q.push_back(n - 1);
      q.push_back(n);
      q.push_back(n - 1);
    }

    // 共通
    for (int i = 0; i < (n - 3) / 2; i++) {
      push2(n - 2);
      push2(n - 3);
    }

    f(f, n - 4);
  };

  // 最初
  if (N % 2 == 0) { // 偶数
    q.push_back(N - 1);
    for (int i = 0; i < (N - 1) / 2; i++) {
      push2(N);
      push2(N - 1);
    }
    push2(N);
  } else { // 奇数
    q.push_back(N);
    for (int i = 0; i < (N - 1) / 2; i++) {
      push2(N - 1);
      push2(N);
    }
  }
  f(f, N - 2);
    
  vector<int> ans;
  for (auto it = q.begin(); it != q.end(); it++) {
    ans.push_back(*it);
  }
  dumpvec(ans);
  return 0;
}
