/*find how many carry operations
 *in add two given numbers
 */

#include <cstdio>

using namespace std;

int A[11];
int B[11];
int answer[22];

int add()
{
    int carry=0;
    for(int i=0;i<11;i++)
        answer[i] = A[i]+B[i];
    //do carry
    for(int i=0;i<15-1;i++)
    {
        if(answer[i]>=10)
            carry ++;
        answer[i+1] += answer[i]/10;
        answer[i] /=10;
    }
    return carry;
}

int main()
{
    int temp[11];
    int X,Y;
    for(int i=0;i<11;i++)
    {
        A[i]=0;
        B[i]=0;
    }
    for(int i=0;i<22;i++)
        answer[i]=0;
    int carry=0;
    while(scanf("%d %d",&X,&Y)!=EOF && !(X==0 && Y==0))
    {
        //get number
        for(int i=0;X!=0;i++)
        {
            A[i] = X%10;
            X/=10;
        }
        for(int i=0;Y!=0;i++)
        {
            B[i] = Y%10;
            Y/=10;
        }

        carry = add();
        if(carry==0)
            printf("No carry operation.\n");
        else if(carry<=1 && carry>0)
            printf("%d carry operation.\n",carry);
        else if(carry>1)
            printf("%d carry operations.\n",carry);
        for(int i=0;i<11;i++)
        {
            A[i]=0;
            B[i]=0;
        }
        for(int i=0;i<22;i++)
            answer[i]=0;
        }

    return 0;
}
