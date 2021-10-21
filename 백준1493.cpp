#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;
ull lwh[3];
int n;

vector<pair<int, int>> ab;

int inab(int x){
	for (int i = 0; i < n; ++i){
		if (ab[i].fi == x){
			return 1;
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d %d\n", lwh + 0, lwh + 1, lwh + 2, &n);
	int a, b;
	for (int i = 0; i < n; ++i){
		scanf("%d %d\n", &a, &b);
		ab.emplace_back(a, b);
	}
	for (int i = 0; i < 20; ++i){
		if (!inab(i)){
			ab.emplace_back(i, 0);
		}
	}

	sort(ab.begin(), ab.end());

	ull v;
	ull used[20];

	for (int i = 19; i >=0; --i){
		v = 1;
		for (int j = 0; j < 3; ++j)
			v *= (lwh[j]>>i);

		ull temp = 8;
		for (int j = i+1; j < 20; ++j){
			v -= temp * used[j];
			temp *= 8;
		}
		used[i] = (ull)min(v, (ull)ab[i].se);
	}

	if (used[0] != v)
		printf("-1\n");
	else{
		ull ret = 0;
		for (int i = 0; i < 20; ++i){
			ret += used[i];
		}
		printf("%lld\n", ret);
	}

	return 0;
}