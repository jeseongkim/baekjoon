#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
typedef unsigned long long ull;

int n, m;
char asdf[51];
bitset<50> cptm[50];
bitset<50> wcptm = 0b10101010;
bitset<50> bcptm = 0b01010101;
bitset<50> mask = 0b11111111;

int answer(int row, int col){
	int ret0 = 0, ret1 = 0;
	bitset<50> t = 0;
	for (int i = 0; i < 8; i += 2)
	{
		t = (cptm[row + i]>>col)&mask;
		ret0 += (t ^ wcptm).count();

		t = (cptm[row + i + 1]>>col)&mask;
		ret0 += (t ^ bcptm).count();
	}
	for (int i = 0; i < 8; i += 2)
	{
		t = (cptm[row + i]>>col)&mask;
		ret1 += (t ^ bcptm).count();

		t = (cptm[row + i + 1]>>col)&mask;
		ret1 += (t ^ wcptm).count();
	}
	return min(ret0, ret1);
}

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &m, &n);
	for (int i = 0; i < m; ++i){
		scanf("%s\n", asdf);
		cptm[i] = 0;
		for (int j = 0; j < n; ++j)
			cptm[i][j] = (asdf[j] == 'W' ? 0 : 1);
	}

	int ans = 64;
	for (int i = 0; i < m-7; ++i){
		for (int j = 0; j < n-7; ++j){
			ans = min(ans, answer(i, j));
		}
	}

	printf("%d\n", ans);
	return 0;
}