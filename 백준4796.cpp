#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, P, V;

int main(int argc, char const *argv[])
{
	int i = 1;
	while(1){
		scanf("%d %d %d\n", &L, &P, &V);
		if (!L && !P && !V)
			break;
		printf("Case %d: %d\n", i++, L*(V/P) + ((V%P)<L ? (V%P) : L ) );
	}
	return 0;
}