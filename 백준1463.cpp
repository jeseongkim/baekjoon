#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>

using namespace std;
#define fi first
#define se second
#define MAXVALUE 1000000
typedef unsigned long long ull;
int n;
int arr[1000001];

void dp(int x){
	int ret = arr[x-1] + 1;
	if (x%3 == 0)
		ret = min(ret, arr[x/3] + 1);
	if (x%2 == 0)
		ret = min(ret, arr[x/2] + 1);
	arr[x] = ret;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d\n", &n);
	arr[1] = 0;
	for (int i = 2; i <= n; ++i)
		dp(i);
	cout << arr[n];
	return 0;
}