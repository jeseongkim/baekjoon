#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dd, nn;
std::vector<int> vd;
std::vector<int> vn;

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 11; ++i){
		scanf("%d %d\n", &dd, &nn);
		vd.push_back(dd); vn.push_back(nn);
	}
	sort(vd.begin(), vd.end());
	int T = 0;
	for (int i = 0; i < 10; ++i){
		vd[i+1] += vd[i];
		T += vd[i] + 20*vn[i];
	}
	printf("%d\n", T + vd[10] + 20*vn[10]);
	return 0;
}