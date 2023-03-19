#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> ans;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    if (A % 2 == 0) {
      ans.push_back(A);
    }
  }
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  return 0;
}
