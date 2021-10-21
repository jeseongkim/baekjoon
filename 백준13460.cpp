#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n,m;
vector<string> board;

int sol(vector<string> &b, int mov_cnt, int prev_dir);
int go2i(vector<string> &b, int dir);

int main(int argc, char const *argv[])
{
	string temp;
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i){
		cin >> temp;
		board.push_back(temp);
	}

	int tmp, ret = 11, ret_tmp;
	for (int i = 0; i < 4; ++i){
		vector<string> board_tmp(board);
		tmp = go2i(board_tmp, i); // return can go or not.
		if (tmp){ // can move
			ret_tmp = sol(board_tmp, 1, i);
			if (ret_tmp){
				ret = min(ret_tmp, ret);
			}
		}
	}
	cout << (ret == 11 ? -1 :ret) << endl;
	return 0;
}

int go2i(vector<string> &b, int dir){
	newasdf;
}