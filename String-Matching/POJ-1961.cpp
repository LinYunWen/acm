/*
 *using KMP to find out every combination of
 *power string with different length
 */


#include <cstdio>
#include <cstring>

using namespace std;

char input[1000010];
int fail[1000010];
int total_len;

void fail_function()
{
    int len = total_len;
    //printf("%d\n",len);
    fail[0]=-1;
    for(int i=1,cur_pos=-1;i<len;++i){
        while(~cur_pos && input[i]!=input[cur_pos+1])
            cur_pos = fail[cur_pos];
        if(input[i]==input[cur_pos+1]){
            ++cur_pos;
            //printf("cur: %d\n",cur_pos);
        }
        //printf("%c %c",input[i],input[cur_pos+1]);
        fail[i] = cur_pos;

        if(fail[i]!=-1){
            //printf("%d \n",i);
            if((fail[i]+1)%(i+1-fail[i]-1)==0){
                printf("%d %d\n",i+1,(fail[i]+1)/(i+1-fail[i]-1)+1);
            }
        }

    }
    return;
}

int main()
{
    int counter=1;
    while(scanf("%d",&total_len)!=EOF && total_len)
    {
        //printf("%d\n",total_len);
        memset(fail,-1,sizeof(fail));
        scanf("%s",input);
        //printf("%s\n",input);

        printf("Test case #%d\n",counter++);
        fail_function();
        printf("\n");

        input[0]='\0';
    }
    return 0;
}
