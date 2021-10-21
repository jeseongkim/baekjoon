#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int jumin[10001];

vector<int> edge[10001];

int parents[10001];
int node2depth[10001];
int maxdepth = 0;

vector<int> childs[10001];
vector<int> depthnode[10001];
pair<int, int> usu_notusu[10001];


void treeset(int root, int parent, int depth){
    parents[root] = parent;
    depthnode[depth].push_back(root);
    node2depth[root] = depth;
    maxdepth = max(maxdepth, depth);
    for (auto child : edge[root])
    {
        if (child != parent){
            childs[root].push_back(child);
            treeset(child, root, depth + 1);
        }
    }
}

void set_usunotusu(int depth){
    for (auto node : depthnode[depth])
    {
        usu_notusu[node].first = jumin[node];// max jumin when node is selected as usu
        for (auto child : childs[node])
            usu_notusu[node].first += usu_notusu[child].second; // max jumin when child is selected as not usu
        
        usu_notusu[node].second = 0;// max jumin when node is selected as not usu
        for (auto child : childs[node])
            usu_notusu[node].second += max(usu_notusu[child].first, usu_notusu[child].second);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d ", &jumin[i]);

    int temp1, temp2;
    for (int i = 0; i < n-1; ++i)
    {
        scanf("%d %d", &temp1, &temp2);
        edge[temp1].push_back(temp2);
        edge[temp2].push_back(temp1);
    }
    treeset(1, 0, 0);
    for (int depth = maxdepth; depth >= 0; --depth)
        set_usunotusu(depth);

    int result = max(usu_notusu[1].first, usu_notusu[1].second);
    printf("%d\n", result);
    return 0;
}