#include <iostream>
#include <algorithm>
using namespace std;

int space[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
int result = 0;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=m; j++) {
			scanf_s("%1d", &space[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (space[i][j] == 1) {
				if (dp[i - 1][j - 1] == dp[i - 1][j] && dp[i - 1][j - 1] == dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j] + 1;
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}

				if (result < dp[i][j]) result = dp[i][j];
			}
		}
	}

	
	printf("%d", result*result);
}