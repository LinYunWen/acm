#include <stdio.h>

//using namespace std;

int main()
{
    long long a=0,b=0,c=0,d=0;
    double degree=0;

    while(scanf("%lld %lld",&a,&b)==2)
    {
        scanf("%lf",&degree);
        long double number1=(long double)a/b,number2;
        //printf("%llf\n",number1);

        for(d=1; ;d++)
        {
            c=(long long)(number1*d);
            while(a*d >= c*b)
                c++;
            number2=(long double)c/d;
            if(number2-number1<=degree)
            {
                printf("%lld %lld\n",c,d);
                break;
            }
        }
    }
    return 0;
}
