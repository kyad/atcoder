// https://atcoder.jp/contests/typical90/tasks/typical90_b

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> ans;
  for (int i = 0; i < (1 << N); i++) {
    bitset<20> b(i);
    int ok = 1;
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (b.test(j)) {
	count++;
      } else {
	count--;
      }
      if (count < 0) {
	ok = 0;
	break;
      }
    }
    if (ok && (count == 0)) {
      string str;
      for (int j = 0; j < N; j++) {
	str.push_back(b.test(j) ? '(' : ')');
      }
      ans.push_back(str);
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.size() > 0) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans.at(i) << endl;
    }
  } else {
    cout << endl;
  }
  return 0;
}
