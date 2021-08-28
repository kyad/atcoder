#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    m[A]++;
  }
  int max_key = -1;
  int max_value = -1;
  for (auto p : m) {
    if (p.second > max_value) {
      max_key = p.first;
      max_value = p.second;
    }
  }
  cout << max_key << ' ' << max_value << endl;
  return 0;
}
