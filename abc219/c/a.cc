#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  string X;
  cin >> X;
  map<char, char> mp;
  for (int i = 0; i < X.size(); i++) {
    mp[X[i]] = ('a' + i);
  }
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<pair<string, int> > a(N);
  for (int n = 0; n < N; n++) {
    string s;
    for (size_t i = 0; i < S[n].size(); i++) {
      s.push_back(mp[S[n][i]]);
    }
    a.at(n) = make_pair(s, n);
  }
  sort(a.begin(), a.end());
  for (int n = 0; n < N; n++) {
    int idx = a.at(n).second;
    cout << S.at(idx) << endl;
  }
  return 0;
}
