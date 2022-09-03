#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S[0] == '1') {
    cout << "No" <<endl;
    return 0;
  }
  vector<vector<int> > is(8);
  is[1].push_back(7);
  is[2].push_back(4);
  is[3].push_back(8); is[3].push_back(2);
  is[4].push_back(5); is[4].push_back(1);
  is[5].push_back(9); is[5].push_back(3);
  is[6].push_back(6);
  is[7].push_back(10);

  // i行目に立っているピンが存在するならtrue
  // i行目が全て倒れていればfalse
  auto cond1 = [&](int i) {
    for (size_t s = 0; s < is[i].size(); s++) {
      int idx = is[i][s];
      if (S[idx - 1] == '1') {
        return true;
      }
    }
    return false;
  };

  for (int i = 1; i <= 7; i++) {
    if (!cond1(i)) {
      continue;
    }
    for (int j = i + 2; j <= 7; j++) {
      if (!cond1(j)) {
        continue;
      }
      for (int k = i + 1; k < j; k++) {
        if (!cond1(k)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
