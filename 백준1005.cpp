#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define fi first
#define se second
#define printedge(x) printf("e : %d %d\n", x.fi, x.se)

int dp[100001];
int weights[100001];

// void DFS(int root, vector<int> &visited){
void DFS(int root, vector<int> *s2d, vector<int> &visited){
    int childsmax = 0;
    for (auto child : s2d[root])
    {
        if (!visited[child])
        {
            DFS(child, s2d, visited);
            visited[child] = 1;
        }
        childsmax = max(childsmax, dp[child]);
    }
    dp[root] = childsmax + weights[root];
}

int sol(){
    int n,k, target;
    scanf("%d %d", &n, &k);
    vector<int> s2d[100001];
    int s,d;
    for (int i = 0; i < n; ++i)
        scanf("%d", &weights[i+1]);
    for (int i = 0; i < k; ++i){
        scanf("%d %d", &s, &d);
        s2d[d].push_back(s);
    }
    scanf("%d", &target);

    vector<int> visited(n+1);
    DFS(target, s2d, visited);
    return dp[target];
}


int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        printf("%d\n",sol());

    return 0;
}