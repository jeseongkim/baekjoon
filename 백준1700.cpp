#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int n, k;
int gigi[100];
bitset<128> pluged;
int hole_to_gigi[101];
int gigi_to_hole[101];

void answer(int x){
	int next_use[104] = {0,};
	int hole_idx = 0;
	int j;
	for (int i = 0; i < n; ++i){
		j = x+1;
		while( (j<k) && (gigi[j] != hole_to_gigi[i]) ){
			next_use[i]++;
			j++;
		}
		if (next_use[hole_idx] < next_use[i])
			hole_idx = i;

	}

	// unpluged
	pluged[hole_to_gigi[hole_idx]] = 0;

	// pluging
	pluged[gigi[x]] = 1;
	hole_to_gigi[hole_idx] = gigi[x];
	gigi_to_hole[gigi[x]] = hole_idx;

}


int main(int argc, char const *argv[])
{
	int num_hole = 0;
	int cnt = 0;
	int j;
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d \n", gigi + i);

	for (int i = 0; i < k; ++i){
		if (pluged[gigi[i]])
			continue;
		else if (num_hole < n){
			pluged[gigi[i]] = 1;
			gigi_to_hole[gigi[i]] = num_hole;
			hole_to_gigi[num_hole++] = gigi[i];
		}
		else{
			cnt++;
			answer(i);
		}
	}

	printf("%d\n", cnt);
	return 0;
}