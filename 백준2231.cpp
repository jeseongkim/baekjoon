#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int qnsgogkq(int x){
	int ret = x;
	while(x){
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int asdf;
	int flag = 1;
	scanf("%d", &asdf);
	for (int i = 1; i < asdf; ++i)
	{
		if (qnsgogkq(i) == asdf)
		{
			printf("%d\n", i);
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("%d\n", 0);
	}
	return 0;
}