/*using backtracking to find out how to 
 *choose the number for summary as large 
 *as possible but limit in a given size
 */


#include <cstdio>
#include <cstring>

using namespace std;


int N;
int track_num;
int temp_solution[21];
int solution[21];
int duration[21][2];
int total;
int temp_max;
int temp;

void backtrack(int dimension)
{
    if(total>temp_max)
    {
        temp_max=total;
        for(int i=0;i<21;i++)
            solution[i]=temp_solution[i];
    }

        for(int i=dimension;i<track_num;++i)
        {
            //if(duration[i][1]==0)
            //{
                if(total+duration[i][0]<=N)
                {
                    total += duration[i][0];
                    temp_solution[dimension]=duration[i][0];
                    //duration[i][1]=1;

                    backtrack(i+1);

                    total -= duration[i][0];
                    temp_solution[dimension]=-1;
                    //duration[i][1]=0;
                }
        }
    return;
}



int main()
{
    N=0;
    track_num=0;

    //initialize
    memset(duration, 0, sizeof(duration));
    memset(temp_solution,-1, sizeof(temp_solution));
    memset(solution,-1, sizeof(solution));

    while(scanf("%d",&N)!=EOF)
    {
        scanf("%d",&track_num);
        total=0;
        temp_max=0;

        //get input
        for(int i=0;i<track_num;i++)
        {
            scanf("%d",&duration[i][0]);
        }

        backtrack(0);

        //printf("sum:%d\n",dp[N]);
        for(int i=0;i<track_num;i++)
            if(solution[i]!=-1)
                printf("%d ",solution[i]);
        printf("sum:%d\n",temp_max);

        //restart
        memset(duration, 0, sizeof(duration));
        memset(temp_solution,-1, sizeof(temp_solution));
        memset(solution,-1, sizeof(solution));
    }

    return 0;
}
