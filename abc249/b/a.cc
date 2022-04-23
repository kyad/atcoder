#include <iostream>
#include <map>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool have_large = false;
  for (size_t i = 0; i < S.size(); i++) {
    if (S.at(i) >= 'A' && S.at(i) <= 'Z') {
      have_large = true;
    }
  }
  if (!have_large) {
    cout << "No" << endl;
    return 0;
  }
  bool have_small = false;
  for (size_t i = 0; i < S.size(); i++) {
    if (S.at(i) >= 'a' && S.at(i) <= 'z') {
      have_small = true;
    }
  }
  if (!have_small) {
    cout << "No" << endl;
    return 0;
  }
  map<char, int> mp;
  for (size_t i = 0; i < S.size(); i++) {
    mp[S.at(i)]++;
  }
  for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    if (it->second > 1) {
      cout << "No" <<endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
