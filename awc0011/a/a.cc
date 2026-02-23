#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int S, T;
  cin >> S >> T;
  vector<pair<int, long long> > data;
  bool existS = false;
  bool existT = false;
  for (int j = 0; j < M; j++) {
    int p;
    long long v;
    cin >> p >> v;
    data.push_back(make_pair(p, v));
    if (p == S) {
      existS = true;
    }
    if (p == T) {
      existT = true;
    }
  }
  if (!existS) {
    data.push_back(make_pair(S, 0));
  }
  if (!existT) {
    data.push_back(make_pair(T, 0));
  }
  sort(data.begin(), data.end());
  int js = -1, jt = -1;
  for (int j = 0; j < (int)data.size(); j++) {
    if (data.at(j).first == S) {
      js = j;
    }
    if (data.at(j).first == T) {
      jt = j;
    }
  }
  assert(js != -1);
  assert(jt != -1);
  long long ans = 0;
  if (js <= jt) {
    for (int j = js; j <= jt; j++) {
      ans += data.at(j).second;
    }
  } else {
    for (int j = js; j >= jt; j--) {
      ans += data.at(j).second;
    }
  }
  cout << ans << '\n';
  return 0;
}
