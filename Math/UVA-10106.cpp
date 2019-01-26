/*multiple two given number 
 *which is very large
 */

#include <cstdio>
#include <iostream>

using namespace std;

int X[260];
int Y[260];
int answer[620];
bool change[620];

int multi()
{
    //multiple
    for(int i=0 ; i<260 ; i++)
        for(int j=0;j<260;j++)
        {
            answer[i+j] += X[i]*Y[j];
        }

    //do carry
    int temp=-1;
    for(int i=0;i<620-1;i++)
    {
        //temp=answer[i+1];
        answer[i+1] += answer[i]/10;
        answer[i] %= 10;
    }

    //check for output bit
    int degree=0;
    for(int i=620;i>=0;i--)
        if(answer[i]!=0)
        {
            degree=i;
            break;
        }
    return degree;
}

int main()
{
    char C;
    int temp[260];

    //initialize
    for(int i=0;i<260;i++)
    {
        X[i]=0;Y[i]=0;
        temp[i]=0;
    }
    for(int i=0;i<620;i++)
    {
        answer[i]=0;
        change[i]=false;
    }

    int j=0;
    int flag=0;
    int degree=0;
    //while(fgets(C,1,stdin)!=NULL)
    while( scanf("%c",&C)!=EOF)
    {
        // get input number
        if(C>='0' && C<='9')
            temp[j]=C-'0';
        else if(C=='\n')
        {
            if(flag==0)
            {
                int k = j--;
                for(int i=0;j>=0;j--)
                {
                    X[i] = temp[j];
                    i++;
                }

                flag=1;
            }
            else
            {
                int k=j--;
                for(int i=0;j>=0;j--)
                {
                    Y[i] = temp[j];
                    i++;
                }

                flag=0;
            }

            //after getting two numbers
            if(flag==0)
            {
                degree = multi();

                for(int i=degree;i>=0;i--)
                    printf("%d",answer[i]);
                printf("\n");

                for(int i=0;i<260;i++)
                {
                    X[i]=0;Y[i]=0;
                    temp[i]=0;
                }
                for(int i=0;i<620;i++)
                {
                    answer[i]=0;
                    change[i]=false;
                }
            }
            j=-1;
        }
        else
            break;
        j++;
    }

    return 0;
}
