#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m;
vector<vector<int>> bod(50, vector<int>(50));
vector<vector<int>> p2n(50, vector<int>(50));

int asdf[2500] = {0,};
int dirx[5] = {0, -1, 1, 0, 0};
int diry[5] = {0, 0, 0, -1, 1};

vector<int> blizzard(vector<int> &V, int dir, int num);
int explode(vector<int> &V);
vector<int> transform(vector<int> &V);

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d\n", &bod[i][j]);

	int num = n*n-1;
	int px = 0, py = 0, dir = 0;
	int ndir[] = {4,2,3,1};
	while(num > 0){
		int npx = px + dirx[ndir[dir]], npy = py + diry[ndir[dir]];
		while(0 <= npx && npx < n && 0 <= npy && npy < n && p2n[npx][npy] == 0){
			p2n[px][py] = num;
			asdf[num--] = bod[px][py];
			px = npx; py = npy;
			npx += dirx[ndir[dir]]; npy += diry[ndir[dir]];
		}
		dir++; dir %= 4;
	}

	vector<int> V;
	for (int i = 1; i < n*n; ++i)
		if(asdf[i])
			V.push_back(asdf[i]);

	int ans = 0;
	for (int t = 0; t < m; ++t){
		scanf("%d %d\n", &dir, &num);
		V = blizzard(V, dir, num);
		ans += explode(V);
		V = transform(V);
		while(V.size() >= n*n) V.pop_back();
	}
	printf("%d\n", ans);
	return 0;
}

vector<int> blizzard(vector<int> &V, int dir, int num){
	vector<int> ret;
	int px = n/2, py = n/2;
	int k = 0;
	for (int i = 0; i < num; ++i){
		px += dirx[dir]; py += diry[dir];
		if (p2n[px][py] - 1 < V.size())
			V[p2n[px][py] - 1] = 0;
	}
	for (int i = 0; i < V.size(); ++i)
		if (V[i])
			ret.push_back(V[i]);
	return ret;
}

int explode(vector<int> &V){
	int ret = 0;
	while(1){
		vector<int> next;
		for (int i = 0; i < V.size(); ++i){
			int j = i;
			while(j < V.size() && V[i] == V[j])
				j++;
			if (j-i >= 4){
				ret += (j-i) * V[i];
				i = j-1;
				continue;
			}
			next.push_back(V[i]);
		}

		if (V == next)
			return ret;
		V = next;
	}
}

vector<int> transform(vector<int> &V){
	vector<int> ret;
	for (int i = 0; i < V.size();){
		int j = i;
		while(j < V.size() && V[i] == V[j])
			j++;
		ret.push_back(j-i);
		ret.push_back(V[i]);
		i = j;
	}
	return ret;
}
