#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  int Q;
  cin >> Q;
  bool one_called = false;
  long long offset = 0;
  map<int, long long> mp;
  // Get A[i]
  auto get = [&](int i) -> long long {
    assert(i >= 1);
    assert(i <= N);
    if (!one_called) {
      return A[i];
    }
    long long ans = offset;
    if (mp.count(i) > 0) {
      ans += mp[i];
    }
    return ans;
  };
  auto add = [&](int i, long long x) {
    assert(i >= 1);
    assert(i <= N);
    if (!one_called) {
      A[i] += x;
    } else {
      mp[i] += x;
    }
  };
  for (int q = 0; q < Q; q++) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      long long X;
      cin >> X;
      one_called = true;
      mp.clear();
      offset = X;
    } else if (mode == 2) {
      int I;
      long long X;
      cin >> I >> X;
      add(I, X);
    } else {
      int I;
      cin >> I;
      cout << get(I) << endl;
    }
  }
  return 0;
}
