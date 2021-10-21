#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cstring>
#include <set>

using namespace std;
#define fi first
#define se second
#define mod 10007

typedef unsigned long long ull;
int n, k;

int w[101];
int v[101];
ull dp[101][100001]; // () -> value

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d\n", w+i, v+i);

	for (int j = 0; j <= k; ++j)
		dp[0][j] = 0;

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= k; ++j){
			if (j < w[i]) // i-th element can't push
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}