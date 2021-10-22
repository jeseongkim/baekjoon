#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n,m;
vector<string> board;
struct info
{
	int rx, ry, bx, by;
};
int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};

int sol(info cur, int cnt);

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &m);
	string temp;
	for (int i = 0; i < n; ++i){
		cin >> temp;
		board.push_back(temp);
	}

	info cur;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (board[i][j] == 'R'){
				cur.rx = i; cur.ry = j; board[i][j] = '.';
			}
			if (board[i][j] == 'B'){
				cur.bx = i; cur.by = j; board[i][j] = '.';
			}
		}
	}

	int ret = sol(cur, 0);
	cout << (ret == 11? -1 : ret);
	return 0;
}

int sol(info cur, int cnt){
	if (cnt >= 10){
		return 11;
	}

	int ret = 11;

	for (int dir = 0; dir < 4; ++dir){
		info next = cur;
		while(board[next.rx + dirx[dir]][next.ry + diry[dir]] == '.'){
			next.rx += dirx[dir];
			next.ry += diry[dir];
		}

		while(board[next.bx + dirx[dir]][next.by + diry[dir]] == '.'){
			next.bx += dirx[dir];
			next.by += diry[dir];
		}
		if (board[next.bx + dirx[dir]][next.by + diry[dir]] == 'O')
			continue;
		if (board[next.rx + dirx[dir]][next.ry + diry[dir]] == 'O'){
			return cnt + 1;
		}

		if (next.rx == next.bx && next.ry == next.by){
			int rdist = abs(next.rx - cur.rx + next.ry - cur.ry);
			int bdist = abs(next.bx - cur.bx + next.by - cur.by);
			if (rdist > bdist){
				next.rx -= dirx[dir];
				next.ry -= diry[dir];
			}
			else{
				next.bx -= dirx[dir];
				next.by -= diry[dir];
			}
		}
		ret = min(ret, sol(next, cnt+1));
	}
	return ret;
}

