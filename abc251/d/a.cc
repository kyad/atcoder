#include <iostream>
#include <vector>
using namespace std;

int main() {
  int W;
  cin >> W;
  (void)W;
  vector<int> ans;
  for (int m = 1; m <= 99; m++) {
    ans.push_back(m);
  }
  for (int m = 100; m <= 9900; m += 100) {
    ans.push_back(m);
  }
  for (int m = 10000; m <= 990000; m += 10000) {
    ans.push_back(m);
  }
  ans.push_back(1000000);
  cout << ans.size() << endl;
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans.at(i) << (i + 1 == ans.size() ? '\n' : ' ');
  }
  return 0;
}
