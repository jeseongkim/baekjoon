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
#define MAXVALUE (100001)
typedef unsigned long long ull;
int n;
ull sqare[MAXVALUE];
ull dp[MAXVALUE];

void sol(int x){
	dp[x] = x;
	int i = 1;
	while(sqare[i] <= x){
		dp[x] = min(dp[x], dp[x - sqare[i]] + 1);
		i++;
		if (i == 317)
			break;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	// memset(dp, MAXVALUE, sizeof(dp));
	for (int i = 0; i < 317; ++i)
		sqare[i] = i*i;

	for (int i = 1; i <= n; ++i)
		sol(i);

	cout << dp[n] << endl;
	return 0;
}