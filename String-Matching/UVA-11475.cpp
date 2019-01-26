/*
 *using the KMP's fail function and matching function
 *to find out the string which is the read from head 
 *and from tail,and most important is to add the lest
 *character in origin string
 */


#include <cstdio>
#include <cstring>
using namespace std;

char input[1000010];
char reverse_input[1000010];
int pi[1000010];
int length;

inline void fail()
{
    pi[0]=-1;
    for(int i=1,cur_pos=-1;i<length;++i){
        while(~cur_pos && reverse_input[i]!=reverse_input[cur_pos+1])
            cur_pos = pi[cur_pos];
        if(reverse_input[i]==reverse_input[cur_pos+1])
            cur_pos++;
        pi[i] = cur_pos;
    }
    return;
}

inline int matching()
{
    int i,cur_pos;
    for(i=0,cur_pos=-1;i<length;++i)
    {
        while(~cur_pos && input[i]!=reverse_input[cur_pos+1])
            cur_pos = pi[cur_pos];
        if(input[i]==reverse_input[cur_pos+1])
            ++cur_pos;
    }

    return cur_pos;
}

int main()
{
    while(scanf("%s",input)!=EOF)
    {
        length = strlen(input);
        //get the reverse string 
        for(int i=0;i<length;++i)
            reverse_input[i]=input[length-i-1];
        reverse_input[length]='\0';

        //printf("%s\n",reverse_input);

        fail();
        int pos = matching();

        //print answer
        printf("%s",input);
        for(int i=pos+1;i<length;++i)
            printf("%c",reverse_input[i]);
        printf("\n");


    }

    return 0;
}
