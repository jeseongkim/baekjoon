#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define fi first
#define se second

int n,m;
vector<string> board0;

int sol(vector<string> &board1, int mov_cnt, int prev_dir);
int go2i(vector<string> &board1, int dir);
void findpos(vector<string> &board1, pair<int, int> &ball, char c);

int main(int argc, char const *argv[])
{
	string temp;
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i){
		cin >> temp;
		board0.push_back(temp);
	}

	int tmp, ret = 11, ret_tmp;
	for (int i = 0; i < 4; ++i){
		vector<string> board1(board0);
		tmp = go2i(board1, i); // return can go or not.
		// if (tmp){ // can move
		// 	ret_tmp = sol(board_tmp, 1, i);
		// 	if (ret_tmp){
		// 		ret = min(ret_tmp, ret);
		// 	}
		// }
	}
	cout << (ret == 11 ? -1 :ret) << endl;
	return 0;
}

void findpos(vector<string> &board1, pair<int, int> &ball, char c){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (board1[i][j] == c){
				ball.fi = i; ball.se = j;
			}
		}
	}
}

// 0 : 
int go2i(vector<string> &board1, int dir){
	pair<int, int> red, blue;
	findpos(board1, red, 'R');
	findpos(board1, blue, 'B');

	vector<string> board2(board1);
	if (dir == 0){ // go left
		if (red.se < blue.se){ // go red first
			while(board1[red.fi][red.se - 1] = '.'){ // go red
				swap(board1[red.fi][red.se - 1], board1[red.fi][red.se]);
				red.se--;
			}
			while(board1[blue.fi][blue.se - 1] = '.'){ // go blue
				swap(board1[blue.fi][blue.se - 1], board1[blue.fi][blue.se]);
				blue.se--;
			}
			if (board1[red.fi][red.se] == 'O'){
				if (/* condition */){
					/* code */
				}
			}

		}
		else{

		}
	}
	else if (dir == 1){ // go right
		
	}
	else if (dir == 2){ // go right
		
	}
	else{ // go right
		
	}

	// 움직이지 않았다면 0?
	return 1;
}