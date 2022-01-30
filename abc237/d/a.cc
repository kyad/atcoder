#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> prev(N + 1, -1);
  vector<int> next(N + 1, -1);
  for (int i = 1; i <= N; i++) {
    if (S[i - 1] == 'L') {
      if (prev[i - 1] >= 0) {
        next[prev[i - 1]] = i;
      }
      prev[i] = prev[i - 1];
      prev[i - 1] = i;
      next[i] = i - 1;
    } else {
      if (next[i - 1] >= 0) {
        prev[next[i - 1]] = i;
      }
      next[i] = next[i - 1];
      next[i - 1] = i;
      prev[i] = i - 1;
    }
  }
  int idx;
  for (idx = 0; idx <= N; idx++) {
    if (prev[idx] == -1) {
      break;
    }
  }
  while (true) {
    cout << idx;
    if (next[idx] == -1) {
      cout << endl;
      break;
    } else {
      cout << ' ';
      idx = next[idx];
    }
  }
  return 0;
}
