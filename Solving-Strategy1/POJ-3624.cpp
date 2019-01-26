/*(1 or 0 knapsack problem)
 *using dynamic programming to find the
 *solution
 */

#include <cstdio>

using namespace std;

int main()
{
    int table[3410][2];
    int dp[12890];

    for(int i=0;i<3410;i++)
        for(int j=0;j<2;j++)
            table[i][j]=0;
    for(int i=0;i<12890;i++)
        dp[i]=0;

    int num=0;
    int weight=0;
    int max_want=0;
    scanf("%d %d",&num,&weight);
    //while(scanf("%d %d",&num,&weight)!=EOF && num && weight)
    //{
        for(int i=0;i<num;i++)
            scanf("%d %d",&table[i][0],&table[i][1]);

        for(int i=0;i<num;i++)
        {
            //for(int j=weight;j>=0;j--)
            for(int j=weight;j>=table[i][0];j--)
            {
                //if(j-table[i][0]>=0)
                    if(dp[j]<table[i][1]+dp[j-table[i][0]])
                        dp[j] = table[i][1]+dp[j-table[i][0]];
                //printf("%d\n",dp[j]);
            }
        }
        printf("%d\n",dp[weight]);

    return 0;
}
