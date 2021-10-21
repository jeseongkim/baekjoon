#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int K;
std::vector<int> tkarkrtnemf;

int rksmd(int K, int count){
	if (K < 1)
		return 0;

	if (count == 1)
	{
		for (int i = 0; i < 44; ++i)
		{
			if (K == tkarkrtnemf[i])
				return 1;
		}
		return 0;
	}
	else{
		for (int i = 0; i < 44; ++i)
		{
			if (rksmd(K-tkarkrtnemf[i], count - 1))
			{
				return 1;
			}
		}
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	for (int i = 1; i < 45; ++i)
		tkarkrtnemf.push_back(i*(i+1)/2);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d\n", &K);
		printf("%d\n", rksmd(K, 3));
	}
	return 0;
}

