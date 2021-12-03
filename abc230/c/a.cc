#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, A, B, P, Q, R, S;
  cin >> N >> A >> B;
  cin >> P >> Q >> R >> S;
  for (long long i = P; i <= Q; i++) {
    string line;
    for (long long j = R; j <= S; j++) {
      long long a = i - A;
      long long b = j - B;
      if (a == b || a == -b) {
        line.push_back('#');
      } else {
        line.push_back('.');
      }
    }
    cout << line << endl;
  }
  return 0;
}
