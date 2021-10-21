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
ull arr[100000];

ull div_conq(int lo, int hi){
	if (lo==hi)
		return arr[lo];

	int mid = (lo + hi)/2;
	ull left = div_conq(lo, mid), right = div_conq(mid + 1, hi);

	int l = mid, r = mid;
	ull local_min = arr[mid];
	ull local_sum = 1;
	ull ret = max(left, right);
	while(lo < l || r < hi){
		// can go left
		if (lo < l){
			if (r == hi){ // only can go left
				local_min = min(local_min, arr[--l]);
				local_sum++;
				ret = max(ret, local_sum * local_min);
			}
			else if (arr[l-1] > arr[r+1]){ // go left good
				local_min = min(local_min, arr[--l]);
				local_sum++;
				ret = max(ret, local_sum * local_min);				
			}
			else{ // go right good
				local_min = min(local_min, arr[++r]);
				local_sum++;
				ret = max(ret, local_sum * local_min);
			}
		}
		else{ // only go right
				local_min = min(local_min, arr[++r]);
				local_sum++;
				ret = max(ret, local_sum * local_min);
		}
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld\n", arr+i);
	ull ret = div_conq(0, n-1);
	cout << ret << endl;
	return 0;
}