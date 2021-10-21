#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;

int n;

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	function<int (int)> log3 = [&log3] (int x) -> int {return x == 1 ? 0 : log3(x/3)+1;};
	function<int (int)> pow3 = [&pow3](int x) -> int {return x == 0? 1 : 3*pow3(x-1);};
	int k = log3(n);
	int size;
	vector<string> ans[9];
	ans[0].push_back("*");
	for (int i = 1; i <= k; ++i){
		size = pow3(i-1);
		string temp = "";
		for (int j = 0; j < size; ++j){
			ans[i].push_back(ans[i-1][j] + ans[i-1][j] + ans[i-1][j]);
			temp += " ";
		}
		
		for (int j = 0; j < size; ++j)
			ans[i].push_back(ans[i-1][j] + temp + ans[i-1][j]);
		
		for (int j = 0; j < size; ++j)
			ans[i].push_back(ans[i-1][j] + ans[i-1][j] + ans[i-1][j]);		
	}

	for (int i = 0; i < n; ++i){
		cout << ans[k][i] << endl;
	}
	return 0;
}