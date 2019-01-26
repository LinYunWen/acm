/*to find how many cases for two queens
 *on chess broad in given rows and cols
 *and they would not attack each others
 */


#include <cstdio>

using namespace std;

int main()
{

    long long int row=0,col=0;
    long long int answer = 0;
    long long int temp=0;

    while(scanf("%d %d",&row,&col)!=EOF && !(row==0&&col==0))
    {
        //get the larger one
        if(row>=col)
        {
            temp = row;
            row = col;
            col = temp;
        }
        //for direction on rows and cols
        answer +=((row-1)+(col-1))*(row*col);
        //printf("answer:%lld\n",answer);

        answer += 2*(col-row+1)*row*(row-1);

        //for direction on X
        for(long long int i=2;i<row;i++)
            answer += i*(i-1)*4;

        printf("%lld\n",answer);
        answer=0;

    }
    return 0;
}
