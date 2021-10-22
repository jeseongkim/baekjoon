#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
int A[50][50] = {0,}; 
int dirx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int diry[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int visited[50][50];

void vp(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

void ap(){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) scanf("%d\n", &A[i][j]);

	vector<int> cx = {n-2, n-2, n-1, n-1};
	vector<int> cy = {0, 1, 0, 1};

	int dir, s;
	for (int t = 0; t < m; ++t){
		scanf("%d %d\n", &dir ,&s); dir--;
		// 1 ~ 3.
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < cx.size(); ++i){
			// mov(cx, cy, dir, s);
			cx[i] += dirx[dir] * s; cx[i] = cx[i]%n < 0 ? cx[i]%n + n : cx[i]%n;
			cy[i] += diry[dir] * s; cy[i] = cy[i]%n < 0 ? cy[i]%n + n : cy[i]%n;
			A[cx[i]][cy[i]]++;
			visited[cx[i]][cy[i]] = 1;
		}

		// 4.
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (visited[i][j]){
					for (int dir = 1; dir < 8; dir+=2){
						int px = i + dirx[dir], py = j + diry[dir];
						if (0 <= px && px < n && 0 <= py && py < n && A[px][py] > 0){
							A[i][j]++;
						}
					}
				}
			}
		}


		// 5.
		cx.clear(); cy.clear();
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (A[i][j] >= 2 && !visited[i][j]){
					cx.push_back(i); cy.push_back(j);
					A[i][j]-=2;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			ans += A[i][j];
		}
	}
	printf("%d \n", ans);
	return 0;
}