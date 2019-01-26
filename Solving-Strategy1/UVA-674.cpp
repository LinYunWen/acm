/*using dynamic programming to find out how many way 
 *for change coins in 50,25,10,5,1 cent
 */

#include <cstdio>

using namespace std;

int main()
{
    int dollar=0;
    int table[7490];
    table[0]=1;
    int coin[5]={1,5,10,25,50};

    //make dynamic table
    for(int i=1;i<7490;i++)
        table[i]=0;

    for(int j=0;j<5;j++)
    {
        for(int i=coin[j];i<7490;i++)
        {
            if(table[i-coin[j]]>0)
            {
                table[i]+=table[i-coin[j]];
                //printf("%d ",table[i]);
            }
            //printf("%d ",table[i]);
        }
        //printf("\n");
    }

    while(scanf("%d",&dollar)!=EOF)
    {
        printf("%d\n",table[dollar]);
    }

    return 0;
}
