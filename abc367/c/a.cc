#include <algorithm>
#include <cassert>
#include <iostream>
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
  int N, K;
  cin >> N >> K;
  vector<int> R(N);
  for (int i = 0; i < N; i++) {
    cin >> R.at(i);
  }

  vector<int> ans;
  auto f = [&](auto f, const vector<int> &u) -> void {
    int i = u.size();   // 長さ
    if (i == N) { // 終了判定
      int sum = 0;
      for (int value : u) {
        sum += value;
      }
      if (sum % K == 0) {
        dumpvec(u);
      }
      return;
    }
    // 増やす
    for (int add = 1; add <= R.at(i); add++) {
      vector<int> nu(u);
      nu.push_back(add);
      f(f, nu);
    }
    return;
  };
  f(f, vector<int>());
  return 0;
}
