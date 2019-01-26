/*
 *It is a LCS problem
 */

#include <cstdio>
#include <cstring>

using namespace std;

int correct[23];
int input[23];
int LCS[23][23];

int main()
{
    //initialize
    memset(correct,0,sizeof(correct));
    memset(input,0,sizeof(input));
    memset(LCS,0,sizeof(LCS));

    int num=0;
    int pos=0;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        scanf("%d",&pos);
        correct[pos]=i;
    }

    while(scanf("%d",&pos)!=EOF){
        //get input
        input[pos]=1;
        for(int i=2;i<=num;i++){
            scanf("%d",&pos);
            input[pos]=i;
        }


        //do LCS
        int max_num=0;
        for(int i=1;i<=num;i++){
            for(int j=1;j<=num;j++){
                if(correct[i]==input[j])
                    LCS[i][j]=LCS[i-1][j-1]+1;
                else{
                    if(LCS[i-1][j] >= LCS[i][j-1])
                        LCS[i][j] = LCS[i-1][j];
                    else
                        LCS[i][j] = LCS[i][j-1];
                }
                if(LCS[i][j]>=max_num)
                    max_num=LCS[i][j];
            }
        }

        //print answer
        printf("%d\n",max_num);
    }

    return 0;
}
