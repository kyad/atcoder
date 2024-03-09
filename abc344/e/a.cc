#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
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
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  map<int, int> nx, pr;
  nx[0] = A[0];
  for (int i = 0; i <= N - 2; i++) {
    nx[A.at(i)] = A.at(i + 1);
  }
  nx[A.at(N - 1)] = -1;

  pr[-1] = A.at(N - 1);
  for (int i = N - 1; i >= 1; i--) {
    pr[A.at(i)] = A.at(i - 1);
  }
  pr[A.at(0)] = 0;

  auto add = [&](int x, int y) {
    assert(pr.contains(x));
    assert(nx.contains(x));
    //int p = pr[x];
    int n = nx[x];
    nx[x] = y;
    pr[y] = x;
    nx[y] = n;
    pr[n] = y;
  };

  auto del = [&](int x) {
    assert(pr.contains(x));
    assert(nx.contains(x));
    int p = pr[x];
    int n = nx[x];
    nx[p] = n;
    pr[n] = p;
    nx.erase(x);
    pr.erase(x);
  };

  int Q;
  cin >> Q;

  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      add(x, y);
    } else {
      int x;
      cin >> x;
      del(x);
    }
  }

  vector<int> ans;

  int now = nx[0];
  while (now != -1) {
    ans.push_back(now);
    assert(nx.contains(now));
    now = nx[now];
  }

  dumpvec(ans);
  return 0;
}
