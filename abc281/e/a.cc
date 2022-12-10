#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  multiset<int> st;
  vector<long long> B(M);
  for (int i = 0; i < M; i++) {
    st.insert(A[i]);
    B.at(i) = A.at(i);
  }
  sort(B.begin(), B.end());
  vector<long long> ans;
  long long sum = 0;
  for (int i = 0; i < K; i++) {
    sum += B[i];
  }
  ans.push_back(sum);
  multiset<int>::iterator right = st.begin();
  for (int i = 0; i < K - 1; i++) {
    right++;
  }
  int len = K;
  for (int i = 0; i < N - M; i++) {
    // 取る
    multiset<int>::iterator it = st.find(A[i]);
    if (it == right) {
      sum -= *it;
      len--;
      right--;
    } else if (*it <= *right) {  // A[i]が[begin, right]に入っている時
      sum -= *it;
      len--;
    }
    st.erase(it);
    // 加える
    int a = A[i + M];
    st.insert(a);
    if (a <= *right) {  // aが[begin, right]に追加された
      sum += a;
      len++;
    }
    assert((len == K - 1) || (len == K) || (len == K + 1));
    if (len == K - 1) {
      right++;
      sum += *right;
      len++;
    } else if (len == K + 1) {
      sum -= *right;
      right--;
      len--;
    }
    ans.push_back(sum);
  }
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans[i] << ((((int)i) == (int)(ans.size() - 1)) ? '\n' : ' ');
  }
  return 0;
}
