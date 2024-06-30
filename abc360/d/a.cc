#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int naive() {
  int N;
  long long T;
  cin >> N >> T;
  string S;
  cin >> S;
  vector<long long> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
  }
  vector<int> lefts, rights;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '0') {
      lefts.push_back(i);  // 左に進む
    } else {
      rights.push_back(i);
    }
  }
  long long ans = 0;
  for (int i : rights) {
    long long x = X[i];
    for (int j : lefts) {
      long long y = X[j];
      if (x < y && (y - x) <= 2 * T) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

int solve() {
  int N;
  long long T;
  cin >> N >> T;
  string _S;
  cin >> _S;
  vector<long long> _X(N);
  for (int i = 0; i < N; i++) {
    cin >> _X.at(i);
  }
  vector<pair<long long, char> > _XS(N);
  for (int i = 0; i < N; i++) {
    _XS.at(i) = make_pair(_X.at(i), _S.at(i));
  }
  sort(_XS.begin(), _XS.end());
  
  vector<long long> X(N);
  vector<char> S(N);
  for (int i = 0; i < N; i++) {
    X.at(i) = _XS.at(i).first;
    S.at(i) = _XS.at(i).second;
  }

  vector<int> lefts, rights;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '0') {
      lefts.push_back(i);  // 左に進む
    } else {
      rights.push_back(i);
    }
  }
  deque<long long> dq;  // 左に進む蟻を入れるキュー
  int l = 0;  // leftsのindex
  long long ans = 0;
  for (int i : rights) {
    // dqに入れる
    while (l < (int)lefts.size()) {
      int j = lefts[l];
      if (X.at(j) < X.at(i)) {  // 捨てる
        l++;
        continue;
      } else if (X.at(j) <= X.at(i) + T * 2) {
        dq.push_back(X[j]);  // 左に進む蟻
        l++;
      } else {
        break;
      }
    }
    // dqから捨てる
    while (!dq.empty()) {
      if (dq.front() < X.at(i)) {
        dq.pop_front();
        continue;
      } else {
        break;
      }
    }
    long long now = dq.size();
    ans += now;
  }
  cout << ans << endl;
  return 0;
}

int main() {
  solve();
  return 0;
}
