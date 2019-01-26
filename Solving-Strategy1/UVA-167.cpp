/*given every block in chess broad a unique 
 *number and using backtracking to find out
 *the largest summary of putting 8 queens on
 *the 8 blocks without attacking each others
 */

#include <cstdio>

using namespace std;

int chessboard[8][8];
int visit[8][8];
int max_score;
int max;
int temp_solution[8][2];

void count_score(int dimension)
{
    if(dimension==9){
        if(max>max_score)
            max_score=max;
            //printf("%d\n",max);
        return;
    }
    else
    {
        for(int i=0;i<8;i++)
        {
            if(visit[dimension-1][i]==0)
            {
                max += chessboard[dimension-1][i];
                //printf("%d %d %d\n",i,j,max);
                visit[dimension-1][i]=dimension;
                for(int k=0;k<8;k++)
                {
                    //printf("k:%d\n",k);
                    if(visit[dimension-1][k]==0)
                        visit[dimension-1][k]=dimension;
                    if(visit[k][i]==0)
                        visit[k][i]=dimension;
                    if(dimension-1-k>=0)
                    {
                        if(i-k>=0 && visit[dimension-1-k][i-k]==0)
                            visit[dimension-1-k][i-k]=dimension;

                        if(i+k<8 && visit[dimension-1-k][i+k]==0)
                            visit[dimension-1-k][i+k]=dimension;
                            //printf("--%d %d %d %d\n",k,i-k,j-k,j+k);
                    }
                    if(dimension-1+k<8)
                    {
                        if(i-k>=0 && visit[dimension-1+k][i-k]==0)
                            visit[dimension-1+k][i-k]=dimension;

                        if(i+k<8 && visit[dimension-1+k][i+k]==0)
                            visit[dimension-1+k][i+k]=dimension;
                            //printf("++%d %d %d %d\n",k,i+k,j-k,j+k);
                    }
                }
                count_score(dimension+1);

                max -= chessboard[dimension-1][i];
                //printf("%d %d %d\n",i,j,max);
                visit[dimension-1][i]=0;
                for(int k=0;k<8;k++)
                {
                    //printf("k:%d\n",k);
                    if(visit[dimension-1][k]==dimension)
                        visit[dimension-1][k]=0;
                    if(visit[k][i]==dimension)
                        visit[k][i]=0;
                    if(dimension-1-k>=0)
                    {
                        if(i-k>=0 && visit[dimension-1-k][i-k]==dimension)
                            visit[dimension-1-k][i-k]=0;
                        if(i+k<8 && visit[dimension-1-k][i+k]==dimension)
                            visit[dimension-1-k][i+k]=0;
                            //printf("--%d %d %d %d\n",k,i-k,j-k,j+k);
                    }
                    if(dimension-1+k<8)
                    {
                        if(i-k>=0 && visit[dimension-1+k][i-k]==dimension)
                            visit[dimension-1+k][i-k]=0;
                        if(i+k<8 && visit[dimension-1+k][i+k]==dimension)
                            visit[dimension-1+k][i+k]=0;
                            //printf("++%d %d %d %d\n",k,i+k,j-k,j+k);
                    }
                }
            }
        }
    }
    return;
}



int main()
{
    int case_num=0;
    scanf("%d",&case_num);
    while(case_num>0)
    {
        //initialize
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                visit[i][j]=0;

        for(int i=0;i<8;i++)
            for(int j=0;j<2;j++)
                temp_solution[i][j]=-1;

        //get input
        max=0;
        max_score=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                scanf("%d",&chessboard[i][j]);

        count_score(1);

        //print answer
        printf("%5d\n",max_score);

        case_num--;
    }


    return 0;
}
