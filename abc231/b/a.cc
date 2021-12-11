#include <iostream>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> mp;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    mp[S]++;
  }
  string ans;
  int best = -1;
  for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    if (best < it->second) {
      ans = it->first;
      best = it->second;
    }
  }
  cout << ans << endl;
  return 0;
}
