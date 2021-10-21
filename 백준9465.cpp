#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cstring>

using namespace std;
#define fi first
#define se second
#define MAXVALUE 1000000
typedef unsigned long long ull;
int T;
int n;
int arr0[100001];
int arr1[100001];

int score0[100001];
int score1[100001];
// int score2[100001];

int sol(int x){
	memset(score0, 0, sizeof(score0)); // maximum when choose row0
	memset(score1, 0, sizeof(score1)); // maximum when choose row1
	// memset(score2, sizeof(score1)); // maximum when not choose row0 1
	score0[0] = arr0[0];
	score1[0] = arr1[0];
	if (x == 1)
		return max(score0[0], score1[0]);
	score0[1] = arr0[1] + arr1[0];
	score1[1] = arr1[1] + arr0[0];
	for (int i = 2; i < x; ++i){
		// score2[i] = max(score0[i-1], score1[i-1]);
		score0[i] = max(score1[i-1], score1[i-2]) + arr0[i];
		score1[i] = max(score0[i-1], score0[i-2]) + arr1[i];
	}
	return max(score0[x-1], score1[x-1]);
}


int main(int argc, char const *argv[])
{
	scanf("%d\n", &T);
	for (int i = 0; i < T; ++i){
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d\n", arr0 + i);
		for (int i = 0; i < n; ++i)
			scanf("%d\n", arr1 + i);
		cout << sol(n) << endl;
	}
	return 0;
}