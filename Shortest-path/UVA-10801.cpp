/*
 *every elevator can arrive diffrent floors.
 *and we should find out the fastest solution
 *to arrive the certain floor.It is like the
 *shortest path problem.
 */ 

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define INF 9999999

int main()
{
    int elv_num,end_floor;
    while(scanf("%d %d",&elv_num,&end_floor)!=EOF)
    {
        //initialize
        int elv_time[7];
        int elv_floor[101];
        int graph[101][101];
        for(int i=0;i<101;++i)
            for(int j=0;j<101;++j)
                graph[i][j] = INF;

        //get input graph
        for(int i=0;i<elv_num;++i){
            scanf("%d",&elv_time[i]);
            //printf("time: %d\n",elv_time[i]);
        }

        char input[405];
        char* temp_input;
        gets(input);
        for(int i=0;i<elv_num;i++){
            gets(input);
            //printf("input:-%s-\n",input);
            int j=0;
            temp_input = strtok(input," ");
            while(temp_input!=NULL){
                elv_floor[j++] = atoi(temp_input);
                //printf("temp_input:-%s-\n",temp_input);
                temp_input = strtok(NULL," ");
            }

            for(int a=0;a<j;++a){
                int f1 = elv_floor[a];
                for(int b=a+1;b<j;++b){
                    int f2 = elv_floor[b];
                    if(graph[f1][f2]>(f2-f1)*elv_time[i]){
                        graph[f1][f2] = (f2-f1)*elv_time[i];
                        graph[f2][f1] = graph[f1][f2];
                        //printf("f2:%d f1:%d %d weight:%d\n",f2,f1,elv_time[i],graph[f1][f2]);
                    }
                }
            }
        }

        /*
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++)
                if(graph[i][j]!=INF)
                    printf("%d %d %d\n",i,j,graph[i][j]);
        }
        */

        //SPFA
        queue <int> qu;
        int inqueue[101] = {0};
        int dis[101];

        for(int i=0;i<101;++i){
            dis[i] = INF;
        }
        dis[0] = 0;
        inqueue[0] = 1;
        qu.push(0);
        while(!qu.empty())
        {
            int now = qu.front();
            inqueue[now] = 0;
            qu.pop();

            for(int next=0;next<101;++next){
                if(dis[next]>dis[now]+graph[now][next]+60){
                    dis[next] = dis[now]+graph[now][next]+60;
                    if(inqueue[next]==0){
                        qu.push(next);
                        inqueue[next]=1;
                    }
                }
            }
        }

        //print
        if(end_floor==0)
            printf("0\n");
        else if(dis[end_floor]==INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",dis[end_floor]-60);
            //printf("%d %d\n",dis[end_floor],dis[end_floor]-60);
    }
    return 0;
}
