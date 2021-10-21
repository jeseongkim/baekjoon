#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, temp;
std::vector<int> v;

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &N, &L);
	for (int i = 0; i < N; ++i){
		scanf("%d ", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int s = 0, cnt = 0;
	for (int i = 0; i < N; ++i){
		if (v[i] > s){
			cnt++;
			s = v[i] + L-1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}