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

int tjrvks[20][20];

int ispossible(vector<pair<int, int>> &qhtjr, int info, int ROWCOL){
	if (ROWCOL){ // Check col
		for (auto x : qhtjr){
			if (x.se == info){
				return 0;
			}
		}
		return 1;
	}
	else{
		for (auto x : qhtjr){
			if (x.fi == info){
				return 0;
			}
		}
		return 1;
	}
}

int check(int sx, int sy, int dx, int dy, int prev){
	if ((sx > dx) | (sy > dy))
		return 0;

	vector<pair<int, int>> qnftnsanf;
	vector<pair<int, int>> qhtjr;
	int ret = 0;
	for (int i = sx; i <= dx; ++i){
		for (int j = sy; j <= dy; ++j){
			if (tjrvks[i][j] == 1)
				qnftnsanf.emplace_back(i,j);
			if (tjrvks[i][j] == 2)
				qhtjr.emplace_back(i,j);
		}
	}

	if (qnftnsanf.empty())
		return qhtjr.size() == 1 ? 1 : 0;

	for (int i = 0; i < qnftnsanf.size(); ++i){
		if (ispossible(qhtjr, prev ? qnftnsanf[i].fi : qnftnsanf[i].se, !prev)){
			if (prev) // do row
				ret += check(sx, sy, qnftnsanf[i].fi - 1, dy, 0) * check(qnftnsanf[i].fi + 1, sy, dx, dy, 0);
			else
				ret += check(sx, sy, dx, qnftnsanf[i].se - 1, 1) * check(sx, qnftnsanf[i].se + 1, dx, dy, 1);
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	for (int i = 0; i < n*n; ++i)
		scanf("%d\n", &tjrvks[i/n][i%n]);

	int ret = check(0,0,n-1,n-1,0) + check(0,0,n-1,n-1,1);
	printf("%d\n", ret == 0? -1 : ret);
	return 0;
}