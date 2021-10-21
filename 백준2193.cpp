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
ull arr[91];

void dp(int x){
	ull ret =0;
	for (int i = x-2; i >= 0; --i)
		ret += arr[i];
	arr[x] = ret;
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= n; ++i)
		dp(i);
	cout << arr[n] << endl;
	return 0;
}