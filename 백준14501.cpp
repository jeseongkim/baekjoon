#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;

int main(int argc, char const *argv[])
{
	cin >> n;
	int a,b;
	vector<int> ti;
	vector<int> pi;
	for (int i = 0; i < n; ++i){
		cin >> a >> b;
		ti.push_back(a); pi.push_back(b);
	}

	vector<int> dp(n+1);
	for (int i = n-1; i >= 0; --i){
		if (i + ti[i] > n)
			dp[i] = dp[i+1];
		else
			dp[i] = max(dp[i+ti[i]] + pi[i], dp[i+1]);
	}
	printf("%d\n", dp[0]);
	return 0;
}
