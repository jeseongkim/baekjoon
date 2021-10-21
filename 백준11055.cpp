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

int dp[1001];

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d\n", arr + i);

	int ret = 0;
	for (int i = 0; i < n; ++i){
		dp[i] = arr[i];
		for (int j = 0; j < i; ++j){
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
		}
		ret = max(ret, dp[i]);
	}
	cout << ret << endl;
	return 0;
}
