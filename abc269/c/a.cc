#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<int> a;
  for (int i = 0; i < 60; i++) {
    if ((N >> i) & 1) {
      a.push_back(i);
    }
  }
  vector<long long> ans;
  int M = a.size();
  for (int bit = 0; bit < (1<<M); bit++) {
    long long now = 0;
    for (int m = 0; m < M; m++) {
      if ((bit >> m) & 1) {
        now += (1LL<<a[m]);
      }
    }
    ans.push_back(now);
  }
  for (auto _a : ans) {
    cout << _a << endl;
  }

  return 0;
}
