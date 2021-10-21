#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;

ull L, N ,rf, rb;
vector<pair<ull, ull>> xc;

int main(int argc, char const *argv[])
{

	scanf("%d %d %d %d\n", &L, &N, &rf, &rb);
	ull a,b;
	for (ull i = 0; i < N; ++i){
		scanf("%d %d\n", &a, &b);
		xc.emplace_back(a,b);
	}

	sort(xc.begin(), xc.end(),
		[](pair<ull, ull> a, pair<ull, ull> b)->bool
		{
			return a.se > b.se;
		});

	ull prev = 0;
	ull gap_rate = rf - rb;
	ull ret = 0;
	for (ull i = 0; i < N; ++i){
		if (xc[i].fi > prev){
			ret += gap_rate * (xc[i].fi - prev) * xc[i].se;
			prev = xc[i].fi;
		}
	}

	if (a > prev)
		ret += gap_rate * (a - prev) * b;
	printf("%lld\n", ret);
	return 0;
}