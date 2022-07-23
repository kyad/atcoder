#include <iostream>
#include <map>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> mp;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (mp.count(S) == 0) {
      cout << S << endl;
      mp[S] = 1;
    } else {
      int X = mp[S];
      cout << S << '(' << X << ')' << endl;
      mp[S]++;
    }
  }
  return 0;
}
