#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
#define fi first
#define se second

typedef unsigned long long ull;
ull a, b, c;
int n;
bitset<4374> whddl[2187];
bitset<4374> mask1;
bitset<4374> mask2;

ull ret[3] = {0,};

int pow(int k){
	int ret = 1;
	for (int i = 0; i < k; ++i){
		ret *= 3;
	}
	return ret;
}

int check(int row, int col, int k){
	if (!k){
		ret[whddl[row][2*col] + 2 * whddl[row][2*col + 1]]++;
		return 0;
	}
	else{
		int powk = pow(k);
		bitset<4374> comp;
		bitset<4374> mask;
		for (int i = 0; i < 2*powk; ++i)
			comp[i] = mask[i] = 1;

		bitset<4374> temp;
		bitset<4374> zero = 0;
		int zeroflag = 1;
		for (int i = row; i < row + powk; ++i){
			temp = (whddl[i]>>(2*col))&mask;
			comp &= temp;
			zeroflag &= (temp == zero);
		}

		if (comp == (mask1&mask)){
			ret[1]++;
			return 1;
		}
		else if(comp == (mask2&mask)){
			ret[2]++;
			return 2;
		}
		else if(zeroflag){
			ret[0]++;
			return 0;
		}

		for (int i = 0; i < 9; ++i){
			check(row + (i/3)*(powk/3), col + (i%3)*(powk/3), k-1);
		}
		return 0;
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	int temp = n;
	int k = 0;
	while(temp != 1){
		k++;
		temp /=3;
	}

	for (int i = 0; i < n; ++i){
		mask1[2*i] = 1; mask1[2*i + 1] = 0;
		mask2[2*i] = 0; mask2[2*i + 1] = 1;
	}
	for (int i = 0; i < n*n; ++i){
		scanf("%d\n", &temp);
		if (temp == 1){
			whddl[i/n][2*(i%n)] = 1;
			whddl[i/n][2*(i%n) + 1] = 0;
		}
		else if (temp == -1){
			whddl[i/n][2*(i%n)] = 0;
			whddl[i/n][2*(i%n) + 1] = 1;
		}
	}
	check(0, 0, k);
	printf("%lld\n%lld\n%lld\n", ret[2], ret[0], ret[1]);
	return 0;
}