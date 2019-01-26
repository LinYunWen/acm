/*Euclid Problem*/

#include <cstdio>

using namespace std;

int exGCD(int a,int b,int &X,int &Y)
{
    if(b==0)
    {
        X=1;
        Y=0;
        return a;
    }
    else
    {
        int gcd = exGCD(b,a%b,X,Y);
        int temp =X;
        X=Y;
        Y = temp-(a/b)*Y;
        return gcd;
    }
}


int main()
{
    int A=0,B=0;
    int X=0,Y=0;
    int D=0;
    while(scanf("%d %d",&A,&B)!=EOF)
    {
        D = exGCD(A,B,X,Y);

        printf("%d %d %d\n",X,Y,D);
    }
    return 0;
}
