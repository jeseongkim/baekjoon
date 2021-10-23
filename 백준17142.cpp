#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n,m;
struct virus
{
	int rx, ry, cnt;
};

int hw(int x){
	int ret = 0;
	for (int i = 0; i < 10; ++i)
		ret += (x>>i) &1;
	return ret;
}


int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};

int fulldifussion(vector<vector<int>> &v){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(!v[i][j])
				return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	virus temp;
	vector<virus> vs;
	vector<vector<int>> beuk;

	vector<vector<int>> bod(n, vector<int>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> bod[i][j];
			if (bod[i][j] == 2){
				temp.rx = i; temp.ry = j; temp.cnt = 0;
				vs.push_back(temp);
			}
			else if (bod[i][j] == 1){
				vector<int> v; v.push_back(i); v.push_back(j);
				// temp.rx = i; temp.ry = j; temp.cnt = 0;
				beuk.push_back(v);
			}
		}
	}
	int ans = n*n;
	for (int t = 0; t < (1<<vs.size()); ++t){
		if (hw(t) != m)
			continue;

		queue<virus> q;
		vector<vector<int>> visit(n, vector<int>(n));
		for (auto b : beuk)
			visit[b[0]][b[1]] = 1;

		for (int i = 0; i < vs.size(); ++i){
			if ((t>>i) & 1){
				visit[vs[i].rx][vs[i].ry] = 1;
				q.push(vs[i]);
			}
		}

		int ret = 0;
		while(!q.empty()){
			virus cur = q.front(); q.pop();
			if (!bod[cur.rx][cur.ry]) // if not virus
				ret = cur.cnt;

			for (int dir = 0; dir < 4; ++dir){
				int npx = cur.rx + dirx[dir], npy = cur.ry + diry[dir];
				if (0 <= npx && npx < n && 0 <= npy && npy < n && !visit[npx][npy]){
					visit[npx][npy] = 1;
					temp.rx = npx; temp.ry = npy; temp.cnt = cur.cnt + 1;
					q.push(temp);
				}
			}
		}
		if (fulldifussion(visit))
			ans = min(ans, ret);
	}
	printf("%d\n", ans == n*n ? -1 : ans);
	return 0;
}
