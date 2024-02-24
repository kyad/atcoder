#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> P(26);
  for (int i = 0; i < 26; i++) {
    P.at(i) = i;
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    char c, d;
    cin >> c >> d;
    int cc = c - 'a';
    int dd = d - 'a';
    for (int i = 0; i < 26; i++) {
      if (P[i] == cc) {
        P[i] = dd;
      }
    }
  }
  string ans;
  for (char c : S) {
    int cc = c - 'a';
    ans.push_back(P[cc] + 'a');
  }
  cout << ans << endl;
  return 0;
}
