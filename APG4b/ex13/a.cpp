#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  int average = 0;
  for (int i = 0; i < n; i++) {
    average += a.at(i);
  }
  average /= n;
  for (int i = 0; i < n; i++) {
    cout << abs(a.at(i) - average) << endl;
  }
  return 0;
}

