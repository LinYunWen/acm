/*
 *It is a LIS problem with positive and negative numbers
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int input[1000000];
int LIS[1000000];
int pre[1000000];
int LIS_end[1000000];
int num;
int max_num;
int index_num;

void Find_LIS()
{
    int i,j;
    int n=0;
    index_num=1;
    LIS_end[0]=input[0];
    LIS[0]=1;
    for(i=1;i<num;i++)
    {
        n=input[i];

        //printf("n:%d ",n);
        if(n>LIS_end[index_num-1]){
            //printf("A%d ",index_num);
            LIS[i] = index_num+1;
            LIS_end[index_num]=n;
            index_num++;
            //printf("A%d ",index_num);
        }
        else
        {
            int* temp_index=lower_bound(LIS_end,LIS_end+index_num,n);
            LIS[i]=temp_index-LIS_end+1;
            LIS_end[temp_index-LIS_end]=n;
            //printf("B%d ",temp_index-LIS_end);
            //LIS[temp_index-LIS_end]=i;
        }
        //printf("\n");

        /*
        LIS[i]=1;
        for(j=0;j<i;j++){
            if(input[j]<input[i] && LIS[j]+1>LIS[i]){
                LIS[i]=LIS[j]+1;
                pre[i] = j;
            }
        }
        if(LIS[i]>max_num)
            max_num=LIS[i];
        */

    //}
        //printf("\n");
        /*
        for(j=0;j<num;j++)
            printf("%2d ",input[j]);
        printf("\n");
        //*/
        /*
        for(j=0;j<num;j++)
            printf("%2d ",LIS[j]);
        printf("\n");
        */
        /*
        for(i=0;i<num;i++)
            printf("%2d ",pre[i]);
        printf("\n");
        */
        /*
        for(j=0;j<index_num;j++)
            printf("%2d ",LIS_end[j]);
        printf("\n");
        */
    }
    return;
}

void print_answer(int pos,int length)
{
    if(length==1){
        printf("%d",input[pos]);
        return;
    }
    else{
        //if()
        for(int i=num-1;i>=0;i--)
            if(LIS[i]==index_num){
                printf("%d\n",input[i]);
                index_num--;
            }
    }

}

int main()
{
    num=0;
    max_num=0;
    memset(input,0,sizeof(input));
    memset(pre,-1,sizeof(pre));
    memset(LIS,-1,sizeof(LIS));
    memset(LIS_end,-1,sizeof(LIS_end));


    while(scanf("%d",&input[num])!=EOF){
        /*
        if(num==0)
            LIS_end[index_num++]=input[0];
        //printf("num:%2d index:%2d \n",num,index_num);
        for(int i=index_num-1;i>=0;i--){
            if(LIS_end[i]<input[num]){
                LIS_end[i+1]=input[num];
                if(i==index_num-1)
                    index_num++;
                break;
            }
        }
        */
        num++;
        /*
        for(int i=0;i<index_num_num;i++)
            printf("%2d ",LIS_end[i]);
        printf("\n");
        */
        //printf("num:%2d index_num:%2d \n",num,index_num);
    //}
    }
    Find_LIS();
    //}
    printf("%d\n-\n",index_num);

    /*
    for(int i=num-1;i>=0;i=pre[i])
        printf("%d\n",input[i]);
    */

    int answer_index=0;
    int answer[1000000];
    for(int i=num-1;i>=0;i--)
        if(LIS[i]==index_num){
            //printf("%d\n",input[i]);
            answer[answer_index++]=input[i];
            index_num--;
        }
    for(int i=answer_index-1;i>=0;i--)
        printf("%d\n",answer[i]);

    return 0;
}
