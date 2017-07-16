#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int INF = 99999999;
const int maxn = 55;

char str[maxn][maxn]; //存储每行
int map[maxn][maxn];
int dis[maxn];
int dist[2*maxn][2*maxn];
int edge[2*maxn][2*maxn];
int num, n, m;

int move[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};



void bfs(int i, int j)
{
    int head = 0, tail = 0;
    int queofx[2550], queofy[2550]; //x的队和y的队
    bool vis[maxn][maxn];
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    vis[i][j] = true;
    queofx[tail] = i;
    queofy[tail++] = j;
    while(head < tail)
    {
        int x = queofx[head];
        int y = queofy[head++];
        if(map[x][y])
        {
            edge[map[i][j]][map[x][y]] = dist[x][y];
        }
        for(int t = 0; t < 4; t++)
        {
            int dx = x+move[t][0];
            int dy = y+move[t][1];
            if(dx >= 1 && dx <= m && dy >= 1 && dy <= n)
            {
                if(!vis[dx][dy] && str[dx][dy] != '#')
                {
                    queofx[tail] = dx;
                    queofy[tail++] = dy;
                    vis[dx][dy] = true;
                    dist[dx][dy] = dist[x][y]+1;
                }
            }
        }
    }
}


int Prim()
{
    int ans;
    int min_edge, min_node;
    for(int i = 1; i <= num; i++)
    {
        dis[i] = INF;
    }
    ans = 0;
    int r = 1;
    for(int i = 1; i <= num-1; i++)
    {
        min_edge = INF;
        dis[r] = -1;
        for(int j = 1; j <= num; j++)
        {
            if(dis[j] >= 0)
            {
                dis[j] = min(dis[j], edge[r][j]);
                if(dis[j] < min_edge)
                {
                    min_edge = dis[j];
                    min_node = j;
                }
            }
        }
        r = min_node;
        ans += min_edge;
    }
    return ans;
}



int main()
{
   int i, j;
   int T;
    cin >> T;
    while(T--)
    {
        //每组数据的初始化不能忘记
        memset(map, 0, sizeof(map));
        num = 0;

        cin >> n >> m; //n列m行
        char s[100];
        gets(s);//测试数据问题，多个空格，需要get(s),不能用getchar();
        for(int i = 1; i <= m; i++) //对每行
        {
            gets(str[i]);
            for(int j = 0; j < n; j++) //每行的字符
            {
                if(str[i][j] == 'A' || str[i][j] == 'S')
                {
                    num++;
                    map[i][j] = num;    //找点
                }
            }
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(map[i][j])
                {
                    bfs(i, j);//从i，j点开始找
                }
            }
        }
        printf("%d\n", Prim());
    }

    return 0;
}
