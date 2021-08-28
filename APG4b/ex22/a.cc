#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p.at(i) = make_pair(a, b);
  }
  sort(p.begin(), p.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << p.at(i).first << ' ' << p.at(i).second << endl;
  }
  return 0;
}
