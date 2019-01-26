/*
 *using Floyd method to find out the shortest
 *path for frog jumps from location A to 
 *location B.
 */

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

double dis[1010][1010];

int main()
{
    int step_num;
    int case_num=1;
    while(scanf("%d",&step_num)!=EOF && step_num)
    {
        //get input
        int pos[1010][2];
        for(int i=0;i<step_num;++i)
            scanf("%d %d",&pos[i][0],&pos[i][1]);

        //make graph
        for(int i=0;i<step_num;++i)
            for(int j=i+1;j<step_num;++j){
                //temp = (double)(pos[i][0]-pos[j][1]);
                dis[i][j] = dis[j][i] = sqrt(pow(pos[i][0]-pos[j][0],2) + pow(pos[i][1]-pos[j][1],2));
            }

        //Floyd
        for(int k=0;k<step_num;++k)
            for(int i=0;i<step_num;++i)
                for(int j=0;j<step_num;++j)
                    dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));

        //print answer
        if(case_num!=1)
            printf("\n");
        printf("Scenario #%d\n",case_num++);
        printf("Frog Distance = %.3f\n",dis[0][1]);

    }

    return 0;
}
