#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <functional>
#include <cstring>
#include <queue>


using namespace std;
#define fi first
#define se second
typedef unsigned long long ull;

int n, m, v;

vector<int> s2d[1001];

void dfs(int v, vector<int> &visit){
	printf("%d ", v);
	visit[v] = 1;
	for (auto child : s2d[v]){
		if (!visit[child]){
			dfs(child, visit);
		}
	}
}

void bfs(int v){
	vector<int> visit(1001);
	queue<int> q;
	q.push(v);
	int tar;
	visit[v] = 1;
	while(!q.empty()){
		tar = q.front(); q.pop();
		printf("%d ", tar);

		for (auto child : s2d[tar]){
			if (!visit[child]){
				visit[child] = 1;
				q.push(child);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d\n", &n, &m, &v);
	int a, b;
	for (int i = 0; i < m; ++i){
		scanf("%d %d\n", &a, &b);
		s2d[a].push_back(b);
		s2d[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		sort(s2d[i].begin(), s2d[i].end());

	vector<int> visit(1001);
	dfs(v, visit);
	cout << endl;
	bfs(v);
	return 0;
}