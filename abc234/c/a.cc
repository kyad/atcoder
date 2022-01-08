#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long K;
  cin >> K;
  vector<int> ans;
  while (K > 0) {
    ans.push_back(K % 2);
    K /= 2;
  }
  reverse(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans[i] * 2;
  }
  cout << endl;
  return 0;
}
