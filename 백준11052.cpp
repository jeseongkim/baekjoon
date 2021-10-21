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

typedef unsigned long long ull;
int n;
int arr[1001];
ull dp[1001];

void sol(int x){
	int i = 1;
	while(i <= n && i <= x){
		dp[x] = max(dp[x], dp[x - i] + arr[i]);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	for (int i = 1; i < n + 1; ++i)
		scanf("%d\n", arr + i);

	for (int i = 1; i <= n; ++i)
		sol(i);
	cout << dp[n] << endl;
	return 0;
}