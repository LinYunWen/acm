/*find the prime factor of given input
 *using prime table
 */

#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 10000000
bool isprime[MAX];
int main()
{
    memset(isprime,1,sizeof(isprime));
    isprime[0] = false;
    isprime[1] = false;

    //making table
    for(int i=2;i<=sqrt(MAX) ; ++i)
        if(isprime[i])
            for(int j=i+i;j<MAX;j+=i)
                isprime[j]=false;

    long long int input=0;
    while(scanf("%lld",&input)!=EOF && input>=0)
    {
        for(long long int i=2;i<MAX;i++)
            if(isprime[i])
                if(input%i==0)
                {
                    printf("    %lld\n",i);
                    input /=i;
                    i=1;
                    if(input==1)
                        break;
                }
        if(input>1)
            printf("    %lld\n",input);
        printf("\n");

    }
    return 0;
}
