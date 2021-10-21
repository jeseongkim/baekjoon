#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ull;
ull k, n;
vector<ull> arr;

int sol(ull l){
	ull cnt = 0;
	for (int i = 0; i < k; ++i){
		cnt += arr[i]/l;
		if (cnt >= n){
			return 1;
		}
	}
	return cnt >= n;
}

int main(int argc, char const *argv[])
{
	ull temp;
	scanf("%lld %lld \n", &k, &n);
	for (int i = 0; i < k; ++i){
		scanf("%lld\n", &temp);
		arr.push_back(temp);
	}

	ull lo = 1, hi = *max_element(arr.begin(), arr.end()), ret;
	while(lo <= hi){
		ull mid = (lo + hi)/2;
		if (sol(mid)){
			lo = mid + 1;
			ret = mid;
		}
		else
			hi = mid - 1;
	}
	printf("%d\n", ret);
	return 0;
}