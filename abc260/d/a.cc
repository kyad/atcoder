#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> P(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  vector<int> ans(N + 1, -1);
  map<int, int> mp;
  vector<vector<int> > nums;
  for (int n = 1; n <= N; n++) {
    int X = P.at(n);
    map<int, int>::iterator it = mp.lower_bound(X);
    if (it == mp.end()) {
      int id = nums.size();
      mp[X] = id;
      vector<int> temp;
      temp.push_back(X);
      nums.push_back(temp);
    } else {
      int y = it->first;
      int id = it->second;
      mp.erase(it);
      mp[X] = id;
      nums[id].push_back(X);
    }
    int id = mp[X];
    if (nums[id].size() == K) {
      // eat
      for (size_t i = 0; i < nums[id].size(); i++) {
        int x = nums[id][i];
        ans[x] = n;
      }
      mp.erase(X);
    }
  }
  for (int n = 1; n <= N; n++) {
    cout << ans[n] << endl;
  }
  return 0;
}
