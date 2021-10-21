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

ull divide_conquer(vector<ull> &arr, int lo, int hi){
	if (lo == hi)
		return arr[lo] * arr[hi];
	int mid = (lo + hi) / 2;
	ull left = divide_conquer(arr, lo, mid), right = divide_conquer(arr, mid + 1, hi);
	ull ret = max(left, right);

	int l = mid, r = mid;
	ull local_min = arr[mid];
	ull local_sum = arr[mid];
	ull local_ret = local_sum * local_min;

	while( lo < l || r < hi){
		// can go left
		if (lo < l){
			if (r == hi){ // only can go left
				local_sum += arr[l-1];
				local_min = min(local_min, arr[l-1]);
				local_ret = max(local_ret, local_sum * local_min);
				l--;
			}
			else if (arr[l-1] > arr[r+1]){ // can go left and right, but go left good
				local_sum += arr[l-1];
				local_min = min(local_min, arr[l-1]);
				local_ret = max(local_ret, local_sum * local_min);
				l--;
			}
			else{ // can go left and right, but go right good
				local_sum += arr[r+1];
				local_min = min(local_min, arr[r+1]);
				local_ret = max(local_ret, local_sum * local_min);
				r++;				
			}
		}
		else{ // only can go right
			local_sum += arr[r+1];
			local_min = min(local_min, arr[r+1]);
			local_ret = max(local_ret, local_sum * local_min);
			r++;							
		}
	}
	return max(ret, local_ret);
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	vector<ull> arr;
	ull temp;
	ull ret = 0;
	for (int i = 0; i < n; ++i){
		scanf("%lld\n", &temp);
		arr.push_back(temp);
	}

	ret = divide_conquer(arr, 0, n-1);
	cout << ret << endl;
	return 0;
}