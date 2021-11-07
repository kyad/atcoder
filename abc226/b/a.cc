#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<vector<int> > st;
  for (int n = 0; n < N; n++) {
    int L;
    cin >> L;
    vector<int> a(L);
    for (int j = 0; j < L; j++) {
      cin >> a.at(j);
    }
    st.insert(a);
  }
  cout << st.size() << endl;
  return 0;
}
