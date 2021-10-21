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
ull arr[1001];
ull m = 10007;
void dp(int x){
	
	arr[x] = (arr[x-1]%m) + (arr[x-2]%m);
	arr[x] %= m;
}


int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; ++i)
		dp(i);
	cout << arr[n] << endl;
	return 0;
}