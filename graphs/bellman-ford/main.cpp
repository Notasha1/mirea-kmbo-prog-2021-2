#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 105;
const int INF = 30000;

struct edge {
    int from, to;
    int w;
};

int n, m;
int dist[MAXN];
vector <edge> e;

int main() {
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        edge curEdge;
        scanf("%d %d %d", &curEdge.from, &curEdge.to, &curEdge.w);
        e.push_back(curEdge);
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;

    for (int i = 1; i <= n; i++) {
        bool changed = false;
        for (int j = 0; j < m; j++) {
            int from = e[j].from, to = e[j].to, w = e[j].w;
            if (dist[from] != INF && dist[from] + w < dist[to]) {
                dist[to] = dist[from] + w;
                changed = true;
            }
        }
        if (!changed)
            break;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    return 0;
}
