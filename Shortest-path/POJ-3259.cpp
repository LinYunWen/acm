/*
 *using Bellman-Ford to find out is there any 
 *negative cycle in the given graph/
 */

#include <cstdio>
#include <cstring>

using namespace std;

int graph[510][510];
int dis[510];
int N,M,W;
#define INF 9999999

void relax(int u,int v)
{
    if(dis[u]+graph[u][v] < dis[v])
        dis[v] = dis[u]+graph[u][v];
    return;
}

bool BellmanFord()
{
    dis[N] = 0;
    for(int i=0;i<N;++i){
        dis[i]=INF;
    }

    for(int i=1;i<N;++i){
        for(int j=1;j<=N;++j){
            for(int k=1;k<=N;++k){
                if(graph[j][k]!=0)
                    relax(j,k);
            }
        }
    }

    for(int j=1;j<=N;++j){
        for(int k=1;k<=N;++k)
            if(graph[j][k]!=0)
                if(dis[j]+graph[j][k]<dis[k])
                    return true;
    }
    return false;
}

int main()
{
    int case_num;
    scanf("%d",&case_num);

    int node1,node2,weight;
    int first = 1;
    while(case_num>0)
    {
        scanf("%d %d %d",&N,&M,&W);
        memset(graph,0,sizeof(graph));
        //memset(dis,0,sizeof(dis));
        for(int i=0;i<M;++i){
            scanf("%d %d %d",&node1,&node2,&weight);
            if(graph[node1][node2]==0 || graph[node1][node2] >weight)
                graph[node1][node2] = graph[node2][node1] = weight;
            //if(graph[node2][node1]==0 || graph[node2][node1] >weight)
                //graph[node2][node1] = weight;
        }

        for(int i=0;i<W;++i){
            scanf("%d %d %d",&node1,&node2,&weight);
            if(graph[node1][node2]>(-1*weight))
                graph[node1][node2] = -1*weight;
        }

        bool negative_cycle;
        negative_cycle = BellmanFord();

        /*
        for(int i=0;i<=N;++i)
            printf("%d ",dis[i]);
        printf("\n");
        */

        //if(first==0)
        //    printf("\n");
        if(negative_cycle)
            printf("YES\n");
        else
            printf("NO\n");

        case_num--;
    }
    return 0;
}
