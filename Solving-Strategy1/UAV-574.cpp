/*
 *using backtracking to find out the solution
 *for summary of given number and need to choose
 *element number from a sequence given number
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int element[13];
int N;
int num;
vector<int> solution[10000];
int temp_solution[13];
int repite[10000];
int temp;
int temp_index;
int flag;
bool compare(int i,int j){return (i<j);}
bool vector_compare(vector<int> a,vector<int> b)
{
    for(int i=0;i<a.size();i++){
        if(a[i]==b[i])
            continue;
        return a[i] > b[i];
    }
    return a.size() > b.size();
}

int sum_up(int dimension,int total)
{
    if(total==N)
    {
        solution[temp_index+1]=solution[temp_index];
        temp_index++;
        return 0;
    }
    else
    {
        for(int i=dimension;i<num;i++)
        {
            if(total+element[i]<=N)
            {

                temp_solution[dimension]=element[i];
                solution[temp_index].push_back(element[i]);

                sum_up(i+1,total+element[i]);
                temp_solution[dimension]=-1;
                solution[temp_index].pop_back();
            }
        }
    }
    return 0;
}

int main()
{
    N=0;
    num=0;

    while (scanf("%d %d",&N,&num)!=EOF && !(N==0 && num==0))
    {
        //initialize and get input
        memset(temp_solution,-1,sizeof(temp_solution));
        memset(element,-1,sizeof(element));
        memset(repite,0,sizeof(repite));
        temp_index=0;
        for(int i=0;i<num;i++)
            scanf("%d",&element[i]);


        printf("Sums of %d:\n",N);

        sum_up(0,0);

        if(temp_index==0)
            printf("NONE\n");
        else{

            //print answer
            sort(solution,solution+temp_index,vector_compare);
            printf("%d",solution[0][0]);
            for(int i=1;i<solution[0].size();i++)
                printf("+%d",solution[0][i]);
            printf("\n");

            //print comdination except first time
            for(int i=1;i<temp_index;i++)
            {
                if(solution[i]!=solution[i-1]){
                    printf("%d",solution[i][0]);
                    for(int j=1;j<solution[i].size();++j)
                        printf("+%d",solution[i][j]);
                    printf("\n");
                }
                //solution[i].clear();
            }

            for(int i=0;i<temp_index;i++)
                solution[i].clear();
        }
    }
    return 0;
}
