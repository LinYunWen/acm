/*use greatest common dividor(GCD)
 *to check if the input step and 
 *mod can generate all intagers in 
 *formula seed(x+1)=[seed(x)+step]%mod
 */

#include <cstdio>

using namespace std;

int gcd(int a,int b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}


int main()
{
    int step=0,mod=0;
    while(scanf("%d %d",&step,&mod)!=EOF && mod)
    {
        if(gcd(step,mod)==1)
            printf("%10d%10d    Good Choice\n",step,mod);
        else
            printf("%10d%10d    Bad Choice\n",step,mod);
        printf("\n");

    }
    return 0;
}
