#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int L = 0;
  while (L < N) {
    if (S[L] == 'a') {
      L++;
    } else {
      break;
    }
  }
  if (L >= N) {
    cout << "Yes" << endl;
    return 0;
  }
  int R = 0;
  while (R < N) {
    if (S[N - R - 1] == 'a') {
      R++;
    } else {
      break;
    }
  }
  int K = R - L;
  int left = 0;
  int right = (int)S.size() - 1;
  if (K > 0) {
    right -= K;
  }
  string ans = "Yes";
  while (right - left >= 1) {
    if (S[left] != S[right]) {
      ans = "No";
      break;
    }
    right--;
    left++;
  }
  cout << ans << endl;
  return 0;
}
