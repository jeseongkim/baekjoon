#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int> arr;

int sol(int k){
	int cnt = 1, remain = k;
	for (int i = 0; i < n; ++i){
		if (remain < arr[i]){
			remain = k;
			cnt++;
		}
		remain -= arr[i];
	}
	return cnt <= m;
}

int main(int argc, char const *argv[])
{
	int temp, sum = 0;
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i){
		scanf("%d\n", &temp);
		arr.push_back(temp);
		sum += temp;
	}
	int maxi = *max_element(arr.begin(), arr.end());
	int lo = maxi, hi = sum, ret;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if (sol(mid)){
			hi = mid - 1;
			ret = mid;
		}
		else
			lo = mid + 1;
	}
	printf("%d\n", ret);
	return 0;
}