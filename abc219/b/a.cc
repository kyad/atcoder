#include <iostream>
#include <string>
using namespace std;

int main() {
  string S1, S2, S3;
  string T;
  string ans;
  cin >> S1;
  cin >> S2;
  cin >> S3;
  cin >> T;
  for (size_t i = 0; i < T.size(); i++) {
    if (T[i] == '1') {
      ans += S1;
    } else if (T[i] == '2') {
      ans += S2;
    } else {
      ans += S3;
    }
  }
  cout << ans << endl;
  return 0;
}
