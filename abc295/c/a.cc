#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> mp;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    mp[A]++;
  }
  int ans = 0;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    ans += (it->second / 2);
  }
  cout << ans << endl;
  return 0;
}
