#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<long long> st;
  vector<long long> rep = {1, 11, 111, 1111, 11111,
    111111, 1111111, 11111111, 111111111, 1111111111,
    11111111111, 111111111111};
  int M = rep.size();
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < M; k++) {
        long long now = rep[i] + rep[j] + rep[k];
        st.insert(now);
      }
    }
  }
  vector<long long> ans;
  for (long long s : st) {
    ans.push_back(s);
  }
  cout << ans.at(N - 1) << endl;
  return 0;
}
