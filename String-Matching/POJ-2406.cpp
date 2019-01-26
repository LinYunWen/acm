/*
 *using KMP to find out the repeat times of element substring
 *for given power string
 */

#include <cstdio>
#include <cstring>

using namespace std;

char input[1000010];
int pi[1000010];
int max_num;
int len;

inline int fail_function()
{
    int length = strlen(input);
    pi[0]=-1;
    for(int i=1,cur_pos=-1;i<length;i++)
    {
        while(~cur_pos && input[i]!=input[cur_pos+1])
            cur_pos=pi[cur_pos];
        if(input[i]==input[cur_pos+1]){
            ++cur_pos;
        }
        pi[i]=cur_pos;
    }

    return 0;
}


int main()
{
    while(scanf("%s",input)!=EOF)
    {
        if(strcmp(input,".")==0)
            return 0;
        len = strlen(input);
        memset(pi,-1,sizeof(pi));
        max_num=0;

        fail_function();

        if(pi[len-1]==-1){
            printf("1\n");
        }
        else{
            int element_len = len-pi[len-1]-1;
            if(len%element_len==0)
                printf("%d\n",len/element_len);
            else
                printf("1\n");
        }
        input[0]='\0';
    }

    return 0;
}
