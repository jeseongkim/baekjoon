#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, maxi;
vector<int> arr;

int can(int mid){
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; ++i){
		if (sum + arr[i] > mid){
			cnt++;
			sum = arr[i];
		}
		else{
			sum += arr[i];
		}
	}
	return cnt <= m;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &m);
	int temp, sum = 0, lo, hi, mid, ret;
	for (int i = 0; i < n; ++i){
		scanf("%d\n", &temp);
		arr.push_back(temp);
		sum += temp;
	}
	maxi = *max_element(arr.begin(), arr.end());

	lo = 0, hi = sum;
	while(lo <= hi){
		mid = (lo + hi)/2;
		if (maxi > mid){
			lo = mid + 1;
			continue;
		}

		if (can(mid)){
			hi = mid - 1;
			ret = mid;
		}
		else
			lo = mid + 1;
	}

	printf("%d\n", ret);
	return 0;
}