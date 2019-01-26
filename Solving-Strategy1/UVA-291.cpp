/*
 *using backtracking to find out all path
 *from 1 to 5
 */

#include <cstdio>

using namespace std;

int solution[9];
int graph[5][5]={{0,1,1,0,1},
                 {1,0,1,0,1},
                 {1,1,0,1,1},
                 {0,0,1,0,1},
                 {1,1,1,1,0}};
int visit[5][5];

int track(int dimension)
{
    if(dimension==9)
    {
        for(int i=0;i<9;i++)
            printf("%d",solution[i]+1);
        printf("\n");
        return 0;
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            if(graph[solution[dimension-1]][i]==1)
            {
                //if(i)
                solution[dimension]=i;
                graph[solution[dimension-1]][i]=-1;
                graph[i][solution[dimension-1]]=-1;
                track(dimension+1);
                graph[solution[dimension-1]][i]=1;
                graph[i][solution[dimension-1]]=1;
            }
        }
    }
    return 0;
}




int main()
{

    solution[0]=0;

    track(1);
    return 0;
}
