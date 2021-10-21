#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cstring>
#include <set>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;

int n, m;
vector<int> arr;

ull dp[1000001];

int main(int argc, char const *argv[])
{
	int temp;
	scanf("%d %d \n", &n, &m);
	for (int i = 0; i < n; ++i){
		scanf("%d ", &temp);
		arr.push_back(temp);
	}

	if (n == 1){
		printf("%d\n", arr[0] - m);
		return 0;
	}

	sort(arr.begin(), arr.end());
	// for (int i = 0; i < n; ++i){
	// 	printf("%d ", arr[i]);
	// }
	// printf("\n");

	int i = n-1;
	int leng = 0, prev_leng = 0;
	int sum = 0;
	int prev_h = arr[i];
	int cnt = 4;
	while(cnt){
		auto pos = lower_bound(arr.begin(), arr.end(), arr[i]);
		// leng = arr.end() - lower_bound(arr.begin(), arr.end(), arr[i]);
		leng = arr.end() - pos;
		sum += prev_leng * (prev_h - arr[i]);


		// i = lower_bound(arr.begin(), arr.end(), arr[i]) - arr.begin();
		i = pos - arr.begin();

		// printf("leng, prev_h, arr, i, sum : %d %d %d %d %d\n", leng, prev_h, arr[i], i, sum);

		if (sum >= m){
			int remain = sum - m;
			// printf("leng, m, sum : %d %d %d \n", leng, m, sum);
			// printf("prev_leng %d\n", prev_leng);
			// printf("remain : %d \n", remain);
			// printf("height : %d\n", arr[i] + remain/prev_leng);
			printf("%d\n", arr[i] + remain/prev_leng);
			break;
		}

		// go next
		prev_h = arr[i], prev_leng = leng;
		i--;
		cnt--;
	}

	return 0;
}