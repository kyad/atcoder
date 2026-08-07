#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  vector<int> Q(N);
  for (int i = 0; i < N; i++) {
    cin >> Q.at(i);
  }
  if (P == Q) {
    cout << "Yes" << endl;
    return 0;
  }
  int left = 0, right = N - 1;
  while (true) {
    assert(left < N);
    if (P.at(left) != Q.at(left)) {
      break;
    }
    left++;
  }
  while (true) {
    assert(right >= 0);
    if (P.at(right) != Q.at(right)) {
      break;
    }
    right--;
  }
  // swap
  int len = right - left + 1;
  assert(len > 0);
  for (int k = 0; k < len / 2; k++) {
    swap(P.at(left + k), P.at(right - k));
  }
  if (P == Q) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
