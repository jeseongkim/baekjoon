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
#define MAXVALUE (10001)
typedef unsigned long long ull;
int n, k;

int dp[MAXVALUE];

int sol(vector<int> &arr){
	for (int i = 1; i < MAXVALUE; ++i)
		dp[i] = MAXVALUE;

	for (int i = 1; i <= k; ++i){
	// for (int i = 1; i <= 1; ++i){
		for (int j = 0; j < arr.size(); ++j){
			if (arr[j] <= i)
				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
		}
	}

	return dp[k] == 10001 ? -1 : dp[k];
}

int main(int argc, char const *argv[])
{
	int temp;
	vector<int> arr;
	set<int> s;

	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; ++i){
		scanf("%d\n", &temp);
		if (!s.count(temp)){
			arr.push_back(temp);
			s.insert(temp);
		}
	}

	sort(arr.begin(), arr.end());

	cout << sol(arr) << endl;
	return 0;
}