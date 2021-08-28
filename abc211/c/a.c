#include <stdio.h>
#include <string.h>

long long dp[10][100020];

int main() {
  char s[100020];
  scanf("%s", s);
  int len = strlen(s);
  int i, j;
  char chokudai[] = "chokudai";
  for (j = 0; j < len; j++) {
    dp[8][j] = 1;
  }
  for (i = 7; i >= 0; i--) {
    for (j = len - 1; j >= 0; j--) {
      if (s[j] == chokudai[i]) {
	dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % (1000000000 + 7);
      } else {
	dp[i][j] = dp[i][j + 1];
      }
    }
  }
  printf("%lld\n", dp[0][0]);
  return 0;
}
