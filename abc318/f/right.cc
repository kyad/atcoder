// https://www.youtube.com/watch?v=2NplR-zHuRw

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template<class T> vector<T> set2vector(const set<T> &s) {
  vector<T> v;
  for (typename set<T>::iterator it = s.begin(); it != s.end(); it++) {
    v.push_back(*it);
  }
  return v;
}

int main() {
  int N;
  cin >> N;
  vector<long long> X(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n);
  }
  vector<long long> L(N);
  for (int n = 0; n < N; n++) {
    cin >> L.at(n);
  }
  sort(L.begin(), L.end());
  set<long long> st;
  // 区間を右半開区間 [l, r)で網羅する場合
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      st.insert(X[i] - L[j]);
      st.insert(X[i] + L[j] + 1);
    }
  }
  vector<long long> xs = set2vector(st);
  int M = xs.size();

  auto judge = [&](long long k) {
    vector<long long> d(N);
    for (int i = 0; i < N; i++) {
      d[i] = abs(X[i] - k);
    }
    sort(d.begin(), d.end());
    bool ans = true;
    for (int i = 0; i < N; i++) {
      if (d[i] > L[i]) {
        ans = false;
        break;
      }
    }
    return ans;
  };

  long long ans = 0;
  for (int m = 0; m < M; m++) {
    long long l = xs[m];
    long long r = m < M - 1 ? xs[m + 1] : l + 1;
    bool jg = judge(l);
    if (jg) {
      long long now = r - l;
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
