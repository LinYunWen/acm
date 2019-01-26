/*using backtracking to find out all 
 *arrangement of the sequence numbers
 */

#include <cstdio>

using namespace std;

int solution[6];
int num;
int S[100];
int check[100];
int first=1;

void backtracking(int dimension)
{
    if(dimension==6)
    {
        //print answer
        printf("%d",solution[0]);
        for(int i=1;i<6;i++)
            printf(" %d",solution[i]);
        printf("\n");
        return;
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            if(check[i]!=1)
            {
                if(solution[dimension-1]>S[i])
                    continue;
                check[i]=1;
                solution[dimension]=S[i];
                backtracking(dimension+1);
                check[i]=0;
            }
        }
    }
    return;
}


int main()
{
    while(scanf("%d",&num)!=EOF && num)
    {
        //initialize
        for(int i=0;i<100;i++)
        {
            check[i]=0;
            S[i]=-1;
        }

        //get input
        for(int i=0;i<num;i++)
            scanf("%d",&S[i]);

        if(first==0)
            printf("\n");
        backtracking(0);
        first=0;
    }
    return 0;
}
