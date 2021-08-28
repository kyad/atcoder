#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int j = 0; j < M; j++) {
    cin >> B.at(j);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int ans = 1000000000 + 1;
  int i = 0;
  int j = 0;
  while (true) {
    int value;
    if (A[i] < B[j]) {
      value = B[j] - A[i];
      i++;
    } else if (A[i] > B[j]) {
      value = A[i] - B[j];
      j++;
    } else {
      cout << 0 << endl;
      return 0;
    }
    ans = min(ans, value);
    if (i >= (int)A.size()) {
      break;
    } else if (j >= (int)B.size()) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
