#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 5;
  vector<int> pt(N);
  for (int i = 0; i < N; i++) {
    cin >> pt.at(i);
  }
  int N2 = 1<<N;
  vector<pair<int, string> > pairs;
  for (int bit = 1; bit < N2; bit++) {
    int sum = 0;
    string name;
    for (int i = 0; i < N; i++) {
      if (bit >> i & 1) {
        sum -= pt.at(i);
        name.push_back('A' + i);
      }
    }
    pairs.push_back(make_pair(sum, name));
  }
  sort(pairs.begin(), pairs.end());
  for (auto [sum, name]: pairs) {
    cout << name << endl;
  }
  return 0;
}
