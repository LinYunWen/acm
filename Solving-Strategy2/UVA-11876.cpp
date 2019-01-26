#include <cstdio>
#include <cstring>

using namespace std;

int table[1000010];
int dividor[1005010];
int mark[50000];
int prime[5200];
int pos=0;
void sieve()
{
    for(int i=2;i<50000;++i){
        if(!mark[i]){
            prime[pos++] = i;
            for(int j=i+i;j<50000;j+=i)
                mark[j]=1;
        }
    }
}

int NOD(int n)
{
    int answer = 1;
    int counter = 0;
    for(int i=0;i<pos && prime[i]*prime[i]<=n;++i){
        if(n%prime[i]==0){
            counter = 0;
            while(n%prime[i]==0){
                counter++;
                n /= prime[i];
            }
            answer *=counter+1;
        }
    }
    if(n!=1)
        answer *=2;
    return answer;
}

int set_table()
{
    table[0]=1;
    //for(int i=1;)
}

int binary(int value,int num,int mode)
{
    int left=0;
    int right=num-1;
    while(left<=right)
    {
        int middle = (left+right)/2;
        if(table[middle]==value)
            return middle;
        else if(table[middle]>value)
            right = middle-1;
        else if(table[middle]<value)
            left = middle+1;

        //printf("%d %d %d\t",left,right,table[middle]);
    }
    if(mode==1)
        return left;
    else
        return left-1;
}


int main()
{
    memset(mark,0,sizeof(mark));
    //sieve();

    memset(dividor,0,sizeof(dividor));
    for(long long int i=1;i<1001010;++i)
        for(long long int j=i;j<1001010;j +=i)
            dividor[j]++;

    int temp_index = 7;
    int temp_num = 18;
    table[0] = 1;
    table[1] = 2;
    table[2] = 4;
    table[3] = 7;
    table[4] = 9;
    table[5] = 12;
    table[6] = 18;

    while(temp_num<1001010 || temp_index<1000010){
        temp_num += dividor[temp_num];
        table[temp_index++] = temp_num;
    }


    int case_num=0;
    while(scanf("%d",&case_num)!=EOF){

        for(int i=1;i<=case_num;++i)
        {
            int low,high;
            scanf("%d %d",&low,&high);

            int answer_low=binary(low,temp_index,1);
            int answer_high=binary(high,temp_index,0);
            //printf("%d %d\n",answer_low,answer_high);
            printf("Case %d: %d\n",i,answer_high-answer_low+1);
        }

    }

    return 0;
}
