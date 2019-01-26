/*
 *LCS problem
 */

#include <cstdio>
#include <cstring>

using namespace std;

char input1[1010];
char input2[1010];
int index1;
int index2;

int LCS[1010][1010];

void Find_LCS()
{
    for(int i=1;i<=index1;i++)
    {
        for(int j=1;j<=index2;j++)
        {
            if(input1[i-1]==input2[j-1])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
            {
                if(LCS[i-1][j]>=LCS[i][j-1])
                    LCS[i][j]=LCS[i-1][j];
                else
                    LCS[i][j]=LCS[i][j-1];
            }
        }
    }
    return;
}



int main()
{
    int first=1;
    while(true)
    {
        index1=0;index2=0;
        if(scanf("%c",&input1[index1++])==EOF)
            return 0;
        while(scanf("%c",&input1[index1]) &&input1[index1]!='\n')index1++;
        while(scanf("%c",&input2[index2]) &&input2[index2]!='\n')index2++;

        memset(LCS,0,sizeof(LCS));

        Find_LCS();

        printf("%d\n",LCS[index1][index2]);

        input1[0]='\0';
        input2[0]='\0';
    }


    return 0;
}
