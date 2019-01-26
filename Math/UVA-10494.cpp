/*divide two given numbers*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

queue<int> q;

int main()
{
    //char input1;
    //char* input1=malloc(sizeof(char)*100);
    char input1[1000000];
    long long int input2=0;
    char op;
    long long int temp_mod=0;
    int empty_flag=1;
    queue<int> temp_dev;

    while(scanf("%s %c %lld",input1,&op,&input2)!=EOF)
    {
        for(int i=0;i<strlen(input1);i++)
            q.push(input1[i]-'0');

            if(!q.empty())
                empty_flag=0;
            int start_flag=0;
            temp_mod=0;
            
            //do %
            if(op=='%')
            {
                start_flag=0;
                while(!q.empty())
                {
                    start_flag=1;
                    temp_mod=(10*temp_mod)+q.front();
                    if(temp_mod>=input2)
                    {
                        temp_mod %= input2;
                    }
                    //printf("temp_mod:%u\n",temp_mod);
                    q.pop();
                }
                //printf("answer:%lld\n",temp_mod);
                if(start_flag==1)
                    printf("%lld\n",temp_mod);
            }
            //do /
            else if(op=='/')
            {
                start_flag=0;
                int do_flag=0;
                while(!q.empty())
                {
                    temp_mod=(10*temp_mod)+q.front();
                    //printf("-temp_mod:%d\n",temp_mod);
                    if(temp_mod>=input2)
                    {
                        start_flag = 1;
                        //printf("temp_mod:%lld\n",temp_mod);
                        for(int i=1;i<=10;i++)
                        {
                            if(input2*i>temp_mod)
                            {
                                //temp_dev=(10*temp_dev)+i-1;
                                temp_dev.push(i-1);
                                temp_mod-=(input2*(i-1));
                                //printf("3  temp_mod:%lld\n",temp_mod);
                                do_flag=1;
                                break;
                            }
                            else if(input2*i==temp_mod)
                            {
                                //temp_dev=(10*temp_dev)+i;
                                temp_dev.push(i);
                                temp_mod-=(input2*(i));
                                do_flag=1;
                                break;
                            }
                        }
                        //printf("temp_dev:%d\n",temp_dev);
                        //printf("temp_mod:%lld\n\n",temp_mod);
                    }
                    if(start_flag==1 && do_flag==0)
                        temp_dev.push(0);
                    do_flag=0;
                    q.pop();
                }
                //printf("answer:%d\n",temp_dev);
                if(temp_dev.empty() && empty_flag==0)
                {
                    //printf("%d %d\n",start_flag,temp_dev.front());
                    temp_dev.push(0);
                }

                //print anwser
                while(!temp_dev.empty())
                {
                    printf("%d",temp_dev.front());
                    temp_dev.pop();
                }
                printf("\n");
            }
    }
    return 0;
}
