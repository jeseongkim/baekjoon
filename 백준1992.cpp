#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;
int n;
bitset<64> dudtkd[64];

string check(int row, int col, int size){
	if (size == 1)
		return dudtkd[row][col] == 0 ? "0" : "1";

	bitset<64> t0 = dudtkd[row];
	bitset<64> t1 = dudtkd[row];

	for (int i = row; i < row + size; ++i){
		t0 |= dudtkd[i];
		t1 &= dudtkd[i];
	}


	ull mask = size != 64 ? ((ull)1<<size)-1 : (ull)0xffffffffffffffff;

	if ( ((t0>>col).to_ullong()&mask) == 0)
		return "0";
	if ( ((t1>>col).to_ullong()&mask) == mask)
		return "1";

	// cout<< " t1 : " << (t1>>col).to_ullong() << endl;
	// cout<< " t1 : " << ( (t1>>col).to_ullong() == ((1<<size) - 1) ) << endl;
	// cout<< ( (1<<size) - 1 ) <<endl;
	string ret = "(";
	int hsize = size/2;
	for (int i = 0; i < 4; ++i)
		ret += check(row + (i/2) * hsize, col + (i%2) * hsize, hsize);
	return ret + ")";
}

int main(int argc, char const *argv[])
{
	char asdf[65];
	scanf("%d\n", &n );
	for (int i = 0; i < n; ++i){
		scanf("%s\n", asdf);
		for (int j = 0; j < n; ++j)
			dudtkd[i][j] = asdf[j] == '0' ? 0 : 1;
	}

	string ret = check(0, 0, n);
	cout << ret << endl;
	return 0;
}