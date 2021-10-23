#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
struct fish
{
	int rx, ry, dir, point;
};

int dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void pV(vector<vector<int>> &p2i, vector<fish> &V){
	printf("idx(V[idx].point, V[idx].dir)\n");
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			printf("%d(%d,%d)\t", p2i[i][j], V[p2i[i][j]].point, V[p2i[i][j]].dir);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

int sol(vector<vector<int>> &p2i, vector<fish> &V, fish shark);

int main(int argc, char const *argv[])
{
	int idx, b;
	vector<fish> V(17);
	vector<vector<int>> p2i(4, vector<int>(4));
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			cin >> idx >> b;
			p2i[i][j] = idx;
			V[idx].rx = i; V[idx].ry = j; V[idx].dir = b-1; V[idx].point = idx;
		}
	}

	// init
	fish shark = {0,};
	shark.dir = V[p2i[0][0]].dir;
	shark.point = V[p2i[0][0]].point;
	V[p2i[0][0]].point = 0;

	int ans = sol(p2i, V, shark);
	printf("%d\n", ans);
	return 0;
}

int sol(vector<vector<int>> &p2i, vector<fish> &V, fish shark){
	// 1. move
	for (int idx = 0; idx < 17; ++idx){
		if (!V[idx].point)
			continue;

		int px = V[idx].rx, py = V[idx].ry;
		for (int dir = 0; dir < 8; ++dir){
			int ndir = (V[idx].dir + dir)%8;
			int npx = px + dirx[ndir], npy = py + diry[ndir];
			if (0 <= npx && npx < 4 && 0 <= npy && npy < 4 && !( npx == shark.rx && npy == shark.ry )){
				V[idx].dir = ndir;
				int nidx = p2i[npx][npy];
				swap(V[idx].rx, V[nidx].rx);
				swap(V[idx].ry, V[nidx].ry);
				swap(p2i[px][py], p2i[npx][npy]);
				break;
			}
		}
	}

	// 2. go shark
	int ret = shark.point;
	for (int length = 1; length < 4; ++length){
		int npx = shark.rx + length * dirx[shark.dir], npy = shark.ry + length * diry[shark.dir];
		if (0 <= npx && npx < 4 && 0 <= npy && npy < 4){
			if (!V[p2i[npx][npy]].point){
				continue;
			}
			vector<vector<int>> p2i0(p2i);
			vector<fish> V0(V);
			fish shark0 = {npx, npy, shark.dir, shark.point};
			if (V0[p2i0[npx][npy]].point){ // if point exist <==> if there are fish
				shark0.point += V0[p2i0[npx][npy]].point; // eat
				V0[p2i0[npx][npy]].point = 0;
				shark0.dir = V0[p2i0[npx][npy]].dir;
			}
			ret = max(ret, sol(p2i0, V0, shark0));
		}
	}
	return ret;
}
