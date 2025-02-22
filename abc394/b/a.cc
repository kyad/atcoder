#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, string> > A;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    int len = S.size();
    A.push_back(make_pair(len, S));
  }
  sort(A.begin(), A.end());
  string ans;
  for (int i = 0; i < N; i++) {
    ans += A.at(i).second;
  }
  cout << ans << endl;
  return 0;
}
