#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1000010;
const long long MAX = 0xFFFFFFFF; //数据太大。10亿*100W
queue<int> q;
int first[N], next[N], w[N], Num[N], num;
long long dis[N];
bool vis[N];
int a, b;

struct Edge //结构体存图，方便反向建边
{
	int u, v;
	int ww;
}ee[N];

void input(int u, int v, int cost) //u,v之间加入权值为cost的边
{
	w[num] = cost;
	next[num] = first[u];
	Num[num] = v;
	first[u] = num++;
}

void init()
{
	num = 0;
	memset(first, -1, sizeof(first));
	for(int i = 1; i <= a; ++i)
		dis[i] = MAX;
}

long long spfa(int start)
{
	long long total = 0;
	int temp;


	memset(vis,false,sizeof(vis));

	dis[start] = 0;
	vis[start] = true;

	q.push(start);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		vis[temp] = false;
		for(int i = first[temp]; i != -1; i = next[i]) //邻接表实现
		{
			if(dis[Num[i]] > dis[temp] + w[i])
			{
				dis[Num[i]] = dis[temp] + w[i];
				if(!vis[Num[i]])
				{
					q.push(Num[i]);
					vis[Num[i]] = true;
				}
			}
		}
	}
	for(int i = 1; i <= a; ++i)
		total += dis[i];
	return total;
}

int main()
{
	int T;
	int top;
	long long ans;
	scanf("%d", &T);
	while(T--)
	{
		top = ans = 0;
		scanf("%d%d", &a, &b);//输入点数和要处理的边
		init(); //初始化dis和vis数组
		for(int i = 0; i < b; i++)
		{
			scanf("%d %d %d", &ee[top].u, &ee[top].v, &ee[top].ww);
			input(ee[top].u, ee[top].v, ee[top].ww);
			top++;
		}
		ans += spfa(1);
		init();
		for(int i = 0; i < top; ++i) //反向图
			input(ee[i].v, ee[i].u, ee[i].ww);
		ans += spfa(1);
		printf("%lld\n", ans);
	}
	return 0;
}
