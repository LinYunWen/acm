/*
 *using binary search to find the solution
 *of x in formula p*e^(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x^2+u=0
 *and 0<=x<=1
 */

#include <cstdio>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;
double temp;
int breakpoint;
double solve_binary_search(int n,int value)
{
    double left=0,right=1;
    temp=0;
    while(right-left>=0.00000001)
    {
        double middle = (left+right)/2;
        temp = (p*exp(-middle)+q*sin(middle)+r*cos(middle)+s*tan(middle)+t*middle*middle+u);
        if(temp>value)
        {
            //left = middle+0.0001;
            left = middle;
        }
        else
        {
            //right = middle-0.0001;
            right = middle;
        }

    }
    return right;
}

int main()
{

    double answer=-1;

    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        //printf("%d %d %d %d %d %d\n",p,q,r,s,t,u);

        double temp_num_1=(p*exp(-1.0)+q*sin(1.0)+r*cos(1.0)+s*tan(1.0)+t+u);
        //double temp_num_0=(p*exp(0)+q*sin(0)+r*cos(0)+s*tan(0)+t+u);
        double temp_num_0=(p+q*sin(0)+r*cos(0)+s*tan(0)+u);


        if(p+r+u==0) //deal with answer is 0
            printf("0.0000\n");
        else if(temp_num_1==0) //deal with answer is 1
            printf("1.0000\n");
        else if(temp_num_1>0 || temp_num_0<0){
            printf("No solution\n");
        }
        else
            printf("%.4f\n",solve_binary_search(10000,0));
    }

    return 0;
}
