/*
 *using Bellman-Ford method to find if there
 *is any negative cycle in the given graph.
 *if there is, print possible.
 */


#include <cstdio>
#include <cstring>

using namespace std;

int graph[1010][1010];
int dis[1010];
int N,M;
#define INF 9999999

struct Edge{
    int from;
    int to;
    int len;
};

int main()
{
    int case_num;
    while(scanf("%d",&case_num)!=EOF){
        while(case_num--)
        {
            scanf("%d %d",&N,&M);
            Edge edges[2005];

            //get input
            for(int i=0;i<M;++i){
                scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].len);
            }

            bool negative_cycle = false;


            //bellman-ford
            dis[N] = 0;
            for(int i=1;i<N;++i){
                dis[i]=INF;
            }

            for(int i=1;i<N;++i){
                for(int u=0;u<M;++u){
                    if(dis[edges[u].from]+edges[u].len < dis[edges[u].to])
                        dis[edges[u].to] = dis[edges[u].from]+edges[u].len;
                }
            }

            for(int j=0;j<M;++j)
                if(dis[edges[j].from]+edges[j].len<dis[edges[j].to]){
                    negative_cycle = true;
                    break;
                }

            //print answer
            if(negative_cycle)
                printf("possible\n");
            else
                printf("not possible\n");

        }
    }
    return 0;
}
