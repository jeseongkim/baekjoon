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
int n, r, c;

int check(int n, int r, int c){
	if (n == 1)
		return 2*r + c;
	int m = 1<<(2*n - 2);
	int pown = 1<<(n-1);
	return check(n-1, r%pown, c%pown) + m * (2 * (r/pown) + (c/pown)); 
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d\n", &n, &r, &c);
	printf("%d %d %d\n", n,r,c);
	cout << check(n, r, c) << endl;
	return 0;
}