#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, k;
int dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fire
{
	int rx, ry, mi, si, di;
};


vector<fire> step2(vector<fire> &V){
	vector<fire> ret;
	vector<fire> pos2fire[50][50];
	fire temp;

	for (int i = 0; i < V.size(); ++i)
		pos2fire[V[i].rx][V[i].ry].push_back(V[i]);
	
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if (pos2fire[i][j].size() == 1)
				ret.push_back(pos2fire[i][j][0]);
			else if (pos2fire[i][j].size() > 1 ){
				int m = 0, s = 0, allodd = 1, alleven = 0;
				for (auto f : pos2fire[i][j]){
					m += f.mi;
					s += f.si;
					allodd &= f.di;
					alleven |= f.di;
				}
				m /= 5; s /= pos2fire[i][j].size();
				if (m){
					if (allodd){
						for (int dir = 0; dir < 8; dir+=2){
							temp.rx = i; temp.ry = j; temp.mi = m; temp.si = s; temp.di = dir;
							ret.push_back(temp);
						}
					}
					else if (!(alleven&1)){
						for (int dir = 0; dir < 8; dir+=2){
							temp.rx = i; temp.ry = j; temp.mi = m; temp.si = s; temp.di = dir;
							ret.push_back(temp);
						}
					}
					else{
						for (int dir = 1; dir < 8; dir+=2){
							temp.rx = i; temp.ry = j; temp.mi = m; temp.si = s; temp.di = dir;
							ret.push_back(temp);
						}
					}
				}
			}
		}
	}
	return ret;
}



int main(int argc, char const *argv[])
{
	scanf("%d %d %d\n", &n, &m, &k);
	fire temp;
	vector<fire> V;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < 5; ++j)
			scanf("%d\n", (int *)&temp + j);
		temp.rx--; temp.ry--;
		V.emplace_back(temp);
	}

	for (int t = 0; t < k; ++t){
		// 1.
		for (int i = 0; i < V.size(); ++i){
			V[i].rx += V[i].si * dirx[V[i].di]; V[i].rx = V[i].rx%n < 0 ? V[i].rx%n + n : V[i].rx%n;
			V[i].ry += V[i].si * diry[V[i].di]; V[i].ry = V[i].ry%n < 0 ? V[i].ry%n + n : V[i].ry%n;
		}

		// 2.
		V = step2(V);
	}

	int ans = 0;
	for (int i = 0; i < V.size(); ++i)
		ans += V[i].mi;
	printf("%d\n", ans);
	return 0;
}