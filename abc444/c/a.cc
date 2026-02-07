#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());

  vector<long long> ans;

  // 全部割れた時
  if (N % 2 == 0) {
    long long L = A.at(0) + A.at(N - 1);  // 長さ
    bool ok = true;
    for (int i = 1; i < N / 2; i++) {
      int j = N - 1 - i;
      long long now = A.at(i) + A.at(j);
      if (now != L) {
        ok = false;
      }
    }
    if (ok) {
      ans.push_back(L);
    }
  }

  // Lが残った時
  long long L = A.at(N - 1);
  vector<long long> B;
  for (int i = 0; i < N; i++) {
    if (A.at(i) < L) {
      B.push_back(A.at(i));
    } else {
      break;
    }
  }
  int M = B.size();
  if (M % 2 == 0) {
    bool ok = true;
    for (int i = 0; i < M / 2; i++) {
      int j = M - 1 - i;
      long long now = B.at(i) + B.at(j);
      if (now != L) {
        ok = false;
      }
    }
    if (ok) {
      if (ans.size() == 0 || ans.at(0) != L) {
        ans.push_back(L);
      }
    }
  }
  sort(ans.begin(), ans.end());
  dump(ans);
  return 0;
}
