#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;
#define fi first
#define se second

int n;
vector<pair<int,int>> v;

int main(int argc, char const *argv[])
{
	scanf("%d\n", &n);
	int a,b;
	for (int i = 0; i < n; ++i){
		scanf("%d %d\n", &a, &b);
		v.emplace_back(a,b);
	}

	sort(v.begin(), v.end(),
		[](pair<int, int> a, pair<int, int> b) -> bool
		{
			return a.fi < b.fi;
		});

	int flag[1000] = {0,};
	int min_w = 101 , min_idx;
	int ret = 0;
	int num_w = 0;
	for (int i = 0; i < n; ++i){
		if (v[i].fi > num_w){
			ret += v[i].se;
			num_w++;
			flag[i] = 1;

			if (min_w > v[i].se){
				min_w = v[i].se;
				min_idx = i;
			}
		}
		else if (min_w < v[i].se){
			flag[i] = 1;
			flag[min_idx] = 0;
			ret += (v[i].se - min_w);

			min_w = v[i].se;
			min_idx = i;
			for (int j = 0; j < i; ++j){
				if (flag[j] && (min_w > v[j].se)){
					min_w = v[j].se;
					min_idx = j;
				}
			}
		}
	}

	printf("%d\n", ret);
	return 0;
}
