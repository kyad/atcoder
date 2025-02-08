#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> K(N);
  vector<vector<int> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> K.at(i);
    for (int k = 0; k < K.at(i); k++) {
      int a;
      cin >> a;
      A.at(i).push_back(a);
    }
  }
  vector<map<int, int> > mp(N);  // mp[i]: サイコロiの目a->個数cnt
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < K.at(i); k++) {
      int a = A.at(i).at(k);
      mp[i][a]++;
    }
  }

  double ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double now = 0;
      auto it = mp[j].begin();
      for (auto [a, a_cnt]: mp[i]) {
        while (it != mp[j].end() && it->first < a) {
          it = next(it);
        }
        if (it == mp[j].end()) {
          break;  // 終了
        }
        int b = it->first;
        int b_cnt = it->second;
        if (b == a) {  // 確率計算
          double pa = (double)a_cnt / K.at(i);
          double pb = (double)b_cnt / K.at(j);
          now += (pa * pb);
        }
      }
      ans = max(ans, now);
    }
  }

  cout << setprecision(15) << ans << endl;
  return 0;
}
