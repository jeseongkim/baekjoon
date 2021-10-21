#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ull;
ull n, c;
vector<ull> arr;

int main(int argc, char const *argv[])
{
	scanf("%lld %lld\n", &n, &c);
	ull temp;
	for (int i = 0; i < n; ++i){
		scanf("%lld\n", &temp);
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	vector<ull> sum;
	sum.push_back(arr[0]);
	for (int i = 1; i < n; ++i){
		sum.push_back(sum[i-1] + arr[i]);
	}

	for (auto x : sum){
		printf("%lld\n", x);
	}

	return 0;
}