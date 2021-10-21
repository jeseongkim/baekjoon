#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
int n, s;
int asdf[20];
int ans;

int aaaa(int x){
	int ret = 0;
	for (int i = 0; i < n; ++i){
		if ((x>>i)&1){
			ret += asdf[i];
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &s);
	for (int i = 0; i < n; ++i)
		scanf("%d\n", asdf+i);

	int cnt = 0;
	for (int i = 1; i < (1<<n); ++i){
		if (s == aaaa(i))
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}