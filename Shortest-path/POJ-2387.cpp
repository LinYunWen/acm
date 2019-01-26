/*
 *using Bellman-Ford to find out the shortest path
 *form node1 to nodeN.
 */
 
#include <cstdio>
#include <cstring>

using namespace std;

int graph[1100][1100];
int dis[1100];
int T,N;
int flag;
#define INF 9999999

void relax(int u,int v)
{
    if(dis[u]+graph[u][v] < dis[v]){
        dis[v] = dis[u]+graph[u][v];
        flag=1;
    }
    return;
}

int BellmanFord()
{
    for(int i=1;i<N;++i){
        dis[i]=INF;
    }
    dis[N] = 0;

    for(int i=1;i<N;++i){
        for(int j = N; j >= 1; j--){
            for(int k = N; k >= 1; k--){
                if(graph[j][k]!=0){
                    relax(j,k);
                }
            }
        }
        if(flag==0)
            return 0;
        flag=0;
    }
    return 0;
}

int main()
{
    flag=0;
    scanf("%d %d",&T,&N);

    //memset(graph,0,sizeof(graph));
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            graph[i][j]=0;

    int node1,node2,weight;
    for(int i=0;i<T;++i){
        scanf("%d %d %d",&node1,&node2,&weight);
        if(graph[node1][node2]==0 || graph[node1][node2] >weight)
            graph[node1][node2] = graph[node2][node1] = weight;
        //if(graph[node2][node1]==0 || graph[node2][node1]>weight)
            //graph[node2][node1] = weight;
    }

    BellmanFord();

    printf("%d\n",dis[1]);

    return 0;
}
