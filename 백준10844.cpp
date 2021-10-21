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
#define Max 1000000000

typedef unsigned long long ull;
int n;
ull dp[101][10]; // 길이, 시작 수


int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	for (int i = 0; i < 10; ++i){
		dp[0][i] = 0; dp[1][i] = 1;
	}
	for (int i = 2; i <= n; ++i){
		dp[i][0] = dp[i-1][1] % Max;
		for (int j = 1; j < 9; ++j)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % Max;
		dp[i][9] = dp[i-1][8] % Max;
	}

	ull ret = 0;
	for (int i = 1; i < 10; ++i){
		ret += dp[n][i];
		ret %= Max;
	}
	cout << ret << endl;
	return 0;
}