/*
 *using Floyd to find out shortest path
 *for stockbroker to sprite the message
 */

#include <cstdio>

using namespace std;
#define INF 9999999

int graph[105][105];
int dis[105][105];
int num;

void Floyd()
{
    for(int k=1;k<=num;++k)
        for(int i=1;i<=num;++i)
            for(int j=1;j<=num;++j)
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j] = dis[i][k]+dis[k][j];

    return;
}


int main()
{
    while(scanf("%d",&num)!=EOF && num)
    {
        //memset(graph,0,sizeof(graph));

        //initialize
        for(int i=1;i<=num;++i){
            for(int j=1;j<=num;++j)
                dis[i][j]=INF;
            dis[i][i]=0;
        }

        //get input
        for(int i=1;i<=num;++i){
            int pair_num;
            int node,cost;
            scanf("%d",&pair_num);
            for(int j=1;j<=pair_num;++j){
                scanf("%d %d",&node,&cost);
                //graph[j][node] = cost;
                dis[i][node] = cost;
            }
        }

        Floyd();

        //check
        int min_num = INF;
        int pos;
        int reach_flag=1;
        int disjoint_flag=0;
        for(int i=1;i<=num;++i){
            int max_num=0;
            reach_flag=1;
            for(int j=1;j<=num;++j){
                if(dis[i][j]==INF){
                    reach_flag=0;
                    break;
                }

                if(dis[i][j]!=INF && dis[i][j]>max_num)
                    max_num=dis[i][j];
            }

            if(reach_flag==1){
                disjoint_flag=0;
                if(max_num<min_num){
                    min_num=max_num;
                    pos=i;
                }
            }
        }

        if(disjoint_flag==1)
            printf("disjoint\n");
        else
            printf("%d %d\n",pos,min_num);

    }
    return 0;
}
