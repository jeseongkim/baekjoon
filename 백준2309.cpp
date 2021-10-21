#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> asdf;
	int sum = 0;
	int temp;
	for (int i = 0; i < 9; ++i){
		scanf("%d\n", &temp);
		asdf.emplace_back(temp);
		sum += temp;
	}

	sort(asdf.begin(), asdf.end());
	int a, b;

	for (int i = 0; i < 9; ++i)
	{
		temp = sum - asdf[i];
		for (int j = i+1; j < 9; ++j)
		{
			if (temp == 100+asdf[j])
			{
				a = i;
				b = j;
			}
		}
	}

	asdf.erase(asdf.begin() + a);

	asdf.erase(asdf.begin() + b-1);

	for (auto x : asdf)
	{
		printf("%d\n", x);
	}
	return 0;
}