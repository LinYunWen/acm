/*
 *It is a LCS problem and print the length
 */

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int input1[62510];
int input2[62510];
int LCS[6000][6000];
vector<int> LCS_vector[62510];
int n,p,q;
int index_num1;
int index_num2;

int Find_LCS()
{
    LCS_vector[0].push_back(0);
    for(int i=1;i<=p+1;++i)LCS_vector[i].push_back(0);
    for(int i=1;i<=q+1;++i)LCS_vector[0].push_back(0);
    for(int i=1;i<=p+1;++i)
    {
        for(int j=1;j<=q+1;j++)
        {
            if(input1[i]==input2[j])
                LCS_vector[i].push_back(LCS_vector[i-1][j-1]+1);
                //LCS_vector[i][j]=LCS_vector[i-1][j-1]+1;
            else{
                if(LCS_vector[i-1][j]>=LCS_vector[i][j-1])
                    LCS_vector[i].push_back(LCS_vector[i-1][j]);
                    //LCS_vector[i][j]=LCS_vector[i-1][j];
                else
                    LCS_vector[i].push_back(LCS_vector[i][j-1]);
                    //LCS_vector[i][j]=LCS_vector[i][j-1];
            }
        }
    }

    return 0;
}

int main()
{
    int case_num=0;
    scanf("%d",&case_num);
    int num=0;

    while(case_num>num)
    {
        //printf("hello2\n");
        n=0;p=0;q=0;
        scanf("%d %d %d",&n,&p,&q);

        //get input
        memset(input1,-1,sizeof(input1));
        memset(input2,-1,sizeof(input2));
        memset(LCS,0,sizeof(LCS));
        for(int i=1;i<=p+1;++i)
            scanf("%d",&input1[i]);
        for(int i=1;i<=q+1;++i)
            scanf("%d",&input2[i]);

        Find_LCS();

        //printf("Case %d: %d\n",num+1,LCS[p+1][q+1]);
        printf("Case %d: %d\n",num+1,LCS_vector[p+1][q+1]);
        for(int i=0;i<=p+1;++i)
            LCS_vector[i].clear();
        ++num;
        //printf("hello1\n");
    }
    //printf("hello3\n");
    return 0;
}
