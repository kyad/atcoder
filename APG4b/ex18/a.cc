#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > ret(n, vector<char>(n, '-'));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ret.at(a - 1).at(b - 1) = 'o';
    ret.at(b - 1).at(a - 1) = 'x';
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ret.at(i).at(j);
      if (j == n - 1) {
	cout << endl;
      } else {
	cout << ' ';
      }
    }
  }
  return 0;
}
  
