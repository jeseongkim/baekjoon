#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;
ull a, b, c;

int main(int argc, char const *argv[])
{
	scanf("%d %d %d\n", &a, &b, &c);
	ull ret = 1;
	ull temp = a;
	while(b){
		if (b&1)
			ret *= temp; ret %= c;
		b >>= 1;
		temp *= temp; temp %= c;
	}
	printf("%lld\n", ret);
	return 0;
}