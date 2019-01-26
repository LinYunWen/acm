/*
 *It is a LIS problem
 */

#include <cstdio>
#include <cstring>

using namespace std;

int element[1010];
int LIS[1010];

void LIS_count()
{
    for(int i=0;element[i]!=-1;i++)
    {
        LIS[i]=1;
        for(int j=0;j<i;j++)
            if(element[j]<element[i] && LIS[j]+1>LIS[i])
                LIS[i]=LIS[j]+1;
    }
    return;
}
int main()
{

    int num=0;
    while(scanf("%d",&num)!=EOF)
    {
        //initialize and get input
        memset(element,-1,sizeof(element));
        memset(LIS,0,sizeof(LIS));
        for(int i=0;i<num;i++)
            scanf("%d",&element[i]);

        LIS_count();

        //find max length
        int max_num=0;
        for(int i=0;LIS[i]!=0;i++)
            if(LIS[i]>max_num)
                max_num=LIS[i];

        printf("%d\n",max_num);
    }

    return 0;
}
