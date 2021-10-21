#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cstring>
#include <queue>


using namespace std;
#define fi first
#define se second
typedef unsigned long long ull;

int n;
vector<int> arr;
int m;

int main(int argc, char const *argv[])
{
	int mid, ret, temp = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d\n", &m);
		arr.push_back(m);
		temp += m;
	}
	scanf("%d\n", &m);

	if (temp <= m){
		cout << temp;
	}
	else{

	int lo = 0, hi = m-1;
	while(lo <= hi){
		mid = (lo + hi)/2;

		temp = 0;
		for (int i = 0; i < n; ++i)
			temp += min(mid, arr[i]);

		if (temp <= m){
			ret = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	printf("%d\n", ret);
	}
	return 0;
}