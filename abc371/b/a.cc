#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<bool> used(N, false);
  for (int i = 0; i < M; i++) {
    int A;
    char B;
    cin >> A >> B;
    A--;
    if (!used.at(A) && B == 'M') {
      used.at(A) = true;
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}