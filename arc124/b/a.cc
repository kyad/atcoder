// https://atcoder.jp/contests/arc124/tasks/arc124_b

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  vector<int> b(N);
  for (int n = 0; n < N; n++) {
    cin >> a.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> b.at(n);
  }
  sort(a.begin(), a.end());
  set<int> ans;
  for (int n = 0; n < N; n++) {
    int x = b.at(0) ^ a.at(n);
    vector<int> temp(N);
    for (int i = 0; i < N; i++) {
      temp.at(i) = x ^ b.at(i);
    }
    sort(temp.begin(), temp.end());
    if (a == temp) {
      ans.insert(x);
    }
  }
  cout << ans.size() << endl;
  for (set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}
