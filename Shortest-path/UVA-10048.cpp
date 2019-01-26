/*
 *using Floyd method to find out the shortest 
 *path from given start node to given end node
 *in given graph.
 */


#include <cstdio>
#include <algorithm>

using namespace std;
#define INF 9999999
int dis[101][101];
int node_num;
int edge_num;
int query_num;

int Floyd()
{
    for(int k=1;k<=node_num;++k)
        for(int i=1;i<=node_num;++i)
            for(int j=1;j<=node_num;++j){
                //if(dis[i][j]>dis[i][k]+dis[k][j])
                //    dis[i][j]=dis[i][k]+dis[k][j];
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[j][k]));
            }
    return 0;
}

int main()
{

    int case_num=1;
    while(scanf("%d %d %d",&node_num,&edge_num,&query_num)!=EOF && query_num)
    {
        //initialize
        for(int i=1;i<=node_num;++i){
            for(int j=1;j<=node_num;++j){
                dis[i][j] = INF;
                dis[j][i] = INF;
            }
            dis[i][i]=0;
        }

        //get input
        int from,to,sound;
        for(int i=0;i<edge_num;++i){
            scanf("%d %d %d",&from,&to,&sound);
            dis[from][to] = sound;
            dis[to][from] = sound;
            //printf("%d %d %d\n",from,to,sound);
        }

        if(case_num!=1)
            printf("\n");
        printf("Case #%d\n",case_num++);

        Floyd();

        //print anwser
        for(int i=0;i<query_num;++i){
            scanf("%d %d",&from,&to);
            if(dis[from][to]!=INF)
                printf("%d\n",dis[from][to]);
            else
                printf("no path\n");
        }

        /*
        for(int i=0;i<=node_num;++i){
            for(int j=0;j<=node_num;++j){
                printf("%3d ",dis[i][j]);
            }
            printf("\n");
        }
        */
    }
    return 0;
}
