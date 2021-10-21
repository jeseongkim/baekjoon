#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char asdf[51][51];
char asdft;
int n;

int fdsa(){
	int ret = 1;
	for (int i = 0; i < n; ++i)
	{
		int count = 1;
		char c = asdf[i][0];
		for (int j = 1; j < n; ++j)
		{
			if (c == asdf[i][j]){
				count++;
				ret = max(count, ret);
			}
			else{
				c = asdf[i][j];
				count = 1;
			}
		}
	}

	for (int j = 0; j < n; ++j)
	{
		int count = 1;
		char c = asdf[0][j];
		for (int i = 1; i < n; ++i)
		{
			if (c == asdf[i][j]){
				count++;
				ret = max(count, ret);
			}
			else{
				c = asdf[i][j];
				count = 1;
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", asdf[i]);

	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-1; ++j)
		{
			if (asdf[i][j] != asdf[i][j+1]){
				swap(asdf[i][j], asdf[i][j+1]);
				m = max(m,fdsa());
				swap(asdf[i][j], asdf[i][j+1]);
			}
			if (asdf[j][i] != asdf[j+1][i]){
				swap(asdf[j][i], asdf[j+1][i]);
				m = max(m,fdsa());
				swap(asdf[j][i], asdf[j+1][i]);
			}

		}
	}

	printf("%d\n", m);
	return 0;
}