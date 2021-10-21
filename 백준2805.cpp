#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cstring>

using namespace std;
#define fi first
#define se second
typedef unsigned long long ull;

int n, m;
vector<ull> arr;

ull bisect(int lo, int hi){
	ull mid;
	ull sum;
	ull ret;
	while(lo <= hi){
		mid = (lo + hi)/2;
		sum = 0;
		for (int i = 0; i < n; ++i){
			sum += arr[i] > mid ? arr[i] - mid : 0;
		}
		if (sum == m)
			return mid;
		else if (sum > m){
			ret = mid;
			lo = mid+1;
		}
		else
			hi = mid-1;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int temp;
	int maxi = 0;
	scanf("%d %d \n", &n, &m);
	for (int i = 0; i < n; ++i){
		scanf("%d\n", &temp);
		arr.push_back((ull)temp);
		maxi = max(maxi, temp);
	}

	ull lo = 0, hi = n-1;
	ull ret = bisect(lo, maxi);

	printf("%lld\n", ret);
	return 0;
}