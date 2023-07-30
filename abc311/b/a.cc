#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, D;
	cin >> N >> D;
	vector<string> S(N);
	for (int n = 0; n < N; n++) {
		cin >> S.at(n);
	}
	int ans = 0;
	int now = 0;
	for (int d = 0; d < D; d++) {
		bool ok = true;
		for (int n = 0; n < N; n++) {
			if (S.at(n).at(d) == 'x') {
				ok = false;
				break;
			}
		}
		if (ok) {
			now++;
		} else {
			ans = max(ans, now);
			now = 0;
		}
	}
	ans = max(ans, now);
	cout << ans << endl;
	return 0;
}
